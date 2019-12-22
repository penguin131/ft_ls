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
	int	i;

	i = 0;
	if (argc <= 2)
	{
		info->is_many_folders = 0;
		info->root_file.is_folder = 1;
		ft_strcpy(info->root_file.name, argc == 2 ? argv[1] : ".");
		ft_strcpy(info->root_file.path, "./");
		ft_strcpy(info->root_file.path_name, "./");
		ft_strcat(info->root_file.path_name, info->root_file.name);
		read_folder(info, &info->root_file);
	}
//	else
//	{
//		while (++i < argc)
//		{
//
//		}
//	}

}

int     main(int argc, char **argv)
{
	t_info	info;

	ft_bzero(&info, sizeof(t_info));
	read_folder_args(&info, argc, argv);
	free_data(&info.root_file);
	return (0);
}
