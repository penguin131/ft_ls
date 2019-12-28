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
	while (i < file->length)
	{
		if (ft_strcmp(file->files[i].name, ".") != 0
		&& ft_strcmp(file->files[i].name, "..") != 0
		&& file->files[i].is_folder == 1)
			free_data(&file->files[i]);
		i++;
	}
	ft_memdel((void**)&file->files);
}

void	malloc_error(t_info *info)
{
	free_data(&info->mock_folder);
	exit(0);
}
