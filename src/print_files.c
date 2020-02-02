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

#include <time.h>
#include "ft_ls.h"

void    print_l(t_file *file)
{
    int	i;

    i = 0;
    while (i < file->length)
    {
        ft_printf("%s%s%s",
                  get_chmod[file->files[i].st_mode & 7],
                  get_chmod[(file->files[i].st_mode >> 1) & 7],
                  get_chmod[(file->files[i].st_mode >> 1) & 7]);
        ft_printf("%5d %s %s", 1, file->files[i].username, file->files[i].year);
        //ft_printf("%10d %s", file->files[i].size, ctime(file->files[i].time));
        ft_printf("%35s%10c\n", file->files[i].name, file->files[i].is_folder ? '1' : '0');
        i++;
    }
    ft_printf("\n");
}

void	print_files(t_info *info, t_file *file)
{
	if (info->mock_folder.length > 1 || (info->flags & REC_FL) != 0)
		ft_printf("%s:\n", file->path_name);
	if ((info->flags & L_FLAG) != 0)
	    print_l(file);
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
