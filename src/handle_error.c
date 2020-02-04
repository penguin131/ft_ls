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

void free_data(t_info *info, t_file *file)
{
	int	i;

	i = 0;
	while (file->files && i < file->length)
	{
		file->files[i].name[0] = 0;
		file->files[i].path_name[0] = 0;
		info->pool_len--;
		ft_strdel(&file->files[i].username);
		ft_strdel(&file->files[i].year);
		if (ft_strcmp(file->files[i].name, ".") != 0
		&& ft_strcmp(file->files[i].name, "..") != 0
		&& S_ISDIR(file->files[i].st_mode))
			free_data(info, &file->files[i]);
		i++;
	}
	ft_memdel((void**)&file->files);
}

void	free_list_without_func(t_list **list)
{
	t_list	*tmp;
	t_list	*tmp2;

	tmp = *list;
	while (tmp)
	{
		ft_memdel(&tmp->content);
		tmp2 = tmp->next;
		ft_memdel((void**)&tmp);
		tmp = tmp2;
	}
}

void	malloc_error(t_info *info)
{
	free_data(info, &info->mock_folder);
	exit(0);
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

