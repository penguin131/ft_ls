/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_error.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:20:44 by smight            #+#    #+#             */
/*   Updated: 2019/12/14 15:20:45 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	free_data(t_file *file)
{
	int	i;

	i = 0;
	while (i < file->file_data.length)
	{
		free_data(&file->file_data.files[i]);
	}
	ft_memdel((void**)&file->file_data.files);
}

void    invalid_folder_error(char *folder_name)
{
    ft_printf("ls: %s: No such file or directory", folder_name);
    free_data(root_file);
    exit(0);
}

void	malloc_error()
{
	free_data(root_file);
	exit(0);
}
