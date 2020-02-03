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
	if (info->mock_folder.length > 1 || (info->flags & REC_FL) != 0)
    {
	    if (info->is_not_first != 0)
            ft_printf("\n");
        if (info->mock_folder.length > 1 || info->is_not_first != 0)
        	ft_printf("%s:\n", file->path_name);
		info->is_not_first = 1;
    }
	if ((info->flags & L_FLAG) != 0)
	    print_l(info, file);
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
