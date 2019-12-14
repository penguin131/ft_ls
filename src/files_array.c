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

void	add_new_file(t_data *data, t_file file)
{
	t_file	*new;

	if (data->capacity == data->length)//если вместимость равна длине, то реалочу
	{
		new = ft_memalloc(sizeof(t_file) * (data->capacity = ((data->capacity + 1) * 2)));
		if (!new)
			malloc_error(data);
		if (data->files)
			new = ft_memcpy(new, data->files, data->length * sizeof(t_file));
		ft_memdel((void**)&data->files);
		data->files = new;
	}
	data->files[data->length] = file;
	data->length++;
}
