/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_files.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:58:11 by smight            #+#    #+#             */
/*   Updated: 2019/12/14 15:58:12 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_info *info, t_file *file)
{
	int	i;

	i = 0;
	if (info->mock_folder.length > 1 || (flags & REC_FL) != 0)
		ft_printf("%s:\n", file->path_name);
	while (i < file->length)
	{
		ft_printf("%35s%10c\n", file->files[i].name, file->files[i].is_folder ? '1' : '0');
		i++;
	}
	ft_printf("\n");
}

void    print_invalid_folders(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		if (info->mock_folder.files[i].is_error == 1)
			ft_printf("ls: %s: No such file or directory\n", info->mock_folder.files[i].name);
		i++;
	}
}
