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
		ft_bzero(curr_file.name, MAX_NAME_LEN);
		curr_file.is_error = 0;
		ft_strcat(curr_file.name, argv[info->start]);
		if (!(curr_file.path_name = ft_strdup(curr_file.name)))
			malloc_error(info);
		if (stat(curr_file.name, &buff) == -1)
			curr_file.is_error = 1;
		ft_memcpy(&info->mock_folder.files[i++], &curr_file, sizeof(t_file));
		info->start++;
	}
}

void	create_root_file(t_info *info)
{
	if (!(info->mock_folder.files[0].path_name = ft_strnew(1)))
		malloc_error(info);
	ft_strcpy(info->mock_folder.files[0].name, ".");
	ft_strcpy(info->mock_folder.files[0].path_name, ".");
}

void	read_args(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		if (info->mock_folder.files[i].is_error == 0 &&
			!is_hidden_root(info->mock_folder.files[i].name))
			read_folder(info, &info->mock_folder.files[i]);
		i++;
	}
}

void	free_folders(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		ft_strdel(&info->mock_folder.files[i].path_name);
		free_data(&info->mock_folder.files[i]);
		i++;
	}
}

int     main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	flags = 0;
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
	file_sorting(&info.mock_folder);
	print_invalid_folders(&info);
	read_args(&info);
	free_folders(&info);
	ft_memdel((void**)&info.mock_folder.files);
	return (0);
}
