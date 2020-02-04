/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:11:07 by smight            #+#    #+#             */
/*   Updated: 2019/07/26 11:11:09 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_folder_args(t_info *info, int argc, char **argv)
{
	struct stat	buff;
	t_file		curr_file;
	int 		i;

	i = 0;
	ft_bzero(&curr_file, sizeof(t_file));
	while (info->start < argc)
	{
		//прохожу по всем папкам из аргументов. Пихаю имя
		if (!(curr_file.name = ft_strdup(argv[info->start])) ||
			!(curr_file.path_name = ft_strdup(curr_file.name)))
			malloc_error(info);
		curr_file.is_error = 0;
		if (stat(curr_file.name, &buff) == -1)
			curr_file.is_error = 1;
		ft_memcpy(&info->mock_folder.files[i++], &curr_file, sizeof(t_file));
		info->start++;
	}
}

void	create_root_file(t_info *info)
{
	if (!(info->mock_folder.files[0].name = ft_strdup(".")) ||
		!(info->mock_folder.files[0].path_name = ft_strdup(".")))
		malloc_error(info);
}

void	read_args(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		if (info->mock_folder.files[i].is_error == 0 &&
			!is_hidden_root(info, info->mock_folder.files[i].name))
			read_folder(info, &info->mock_folder.files[i]);
		i++;
	}
}

void	free_info(t_info *info)
{
	int		i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		ft_strdel(&info->mock_folder.files[i].path_name);
		ft_strdel(&info->mock_folder.files[i].name);
		ft_strdel(&info->mock_folder.files[i].username);
		ft_strdel(&info->mock_folder.files[i].year);
		free_data(info, &info->mock_folder.files[i]);
		i++;
	}
	free_list_without_func(&info->reserved_names_pool);
	i = 0;
	while (i < NAMES_CNT)
	{
		ft_memdel((void**)&info->names_pool[i]);
		i++;
	}
	ft_memdel((void**)&info->names_pool);
	ft_memdel((void**)&result.buff);
}

void	malloc_pool(t_info *info)
{
	int i;

	if (!(info->names_pool = ft_memalloc(sizeof(char*) * NAMES_CNT)))
	    malloc_error(info);
	i = 0;
	while (i < NAMES_CNT)
    {
		if (!(info->names_pool[i] = ft_memalloc(sizeof(char) * MAX_PATH_LEN + 1)))
			malloc_error(info);
		i++;
    }
	/**
	 * malloc buffer! need free.
	 */
	 if (!(result.buff = ft_memalloc(sizeof(char) * BUFF_SIZE_P)))
	     malloc_error(info);
}

int     main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	malloc_pool(&info);
	info.flags = 0;
	//читаю флаги и сдвигаю стартовый аргумент, если есть флаги
	read_flags(&info, argc, argv);
	info.mock_folder.length = argc - info.start > 0 ? argc - info.start : 1;
	if (!(info.mock_folder.files = ft_memalloc(sizeof(t_file) * info.mock_folder.length)))
		malloc_error(&info);
	//если аргументы закончились, тобишь есть только флаги, добавляю директорию программы, иначе читаю аргументы
	if (info.start >= argc)
		create_root_file(&info);
	else
		read_folder_args(&info, argc, argv);
    file_sorting(&info, &info.mock_folder);
	print_invalid_folders(&info);
	read_args(&info);
    print_buffer(-1);
	free_info(&info);
	ft_memdel((void**)&info.mock_folder.files);
	return (0);
}
