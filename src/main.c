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
	int			i;
	struct stat	buff;
	t_file		temp_file;
	t_file		curr_file;

	i = 1;
	ft_bzero(&temp_file, sizeof(t_file));
	ft_strcpy(temp_file.path, "./");
	ft_strcpy(temp_file.path_name, "./");
	while (i < argc)
	{
		ft_memcpy(&curr_file, &temp_file, sizeof(t_file));
		ft_strcpy(curr_file.name, argv[i]);
		ft_strcat(curr_file.path_name, argv[i]);
		if (stat(curr_file.path_name, &buff) == -1)
			curr_file.is_error = 1;
		ft_memcpy(&info->mock_folder.files[i - 1], &curr_file, sizeof(t_file));
		i++;
	}
}

void	create_root_file(t_info *info)
{
	ft_strcpy(info->mock_folder.files[0].name, ".");
	ft_strcpy(info->mock_folder.files[0].path, "./.");
	ft_strcpy(info->mock_folder.files[0].path_name, "./");
}

int     main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	info.mock_folder.length = (argc > 1 ? argc : 1) - 1;
	if (!(info.mock_folder.files = ft_memalloc(sizeof(t_file) * info.mock_folder.length)))
		malloc_error(&info);
	if (argc < 2)
		create_root_file(&info);
	else
		read_folder_args(&info, argc, argv);
	file_sorting(&info.mock_folder);
	print_invalid_folders(&info);
	free_data(&info.mock_folder);
	ft_memdel((void**)&info.mock_folder.files);
	return (0);
}
