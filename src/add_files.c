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

	if (file->capacity == file->length)
	{
		new = ft_memalloc(sizeof(t_file) *
				(file->capacity = ((file->capacity + 1) * 2)));
		if (!new)
			malloc_error(info);
		if (file->files)
			new = ft_memcpy(new, file->files, file->length * sizeof(t_file));
		ft_memdel((void**)&file->files);
		file->files = new;
	}
	file->files[file->length] = new_file;
	file->length++;
}
