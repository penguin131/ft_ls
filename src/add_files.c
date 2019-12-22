/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:22:04 by smight            #+#    #+#             */
/*   Updated: 2019/12/14 15:22:06 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

//добавляет новый файл по указателю в массив в дате
void	add_new_file(t_info *info, t_file *file, t_file new_file)
{
	t_file *new;

	if (file->file_data.capacity == file->file_data.length)
	{
		new = ft_memalloc(sizeof(t_file) *
				(file->file_data.capacity = ((file->file_data.capacity + 1) * 2)));
		if (!new)
			malloc_error(info);
		if (file->file_data.files)
			new = ft_memcpy(new, file->file_data.files, file->file_data.length * sizeof(t_file));
		ft_memdel((void**)&file->file_data.files);
		file->file_data.files = new;
	}
	file->file_data.files[file->file_data.length] = new_file;
	file->file_data.length++;
}
