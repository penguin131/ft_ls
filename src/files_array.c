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

void	add_new_name_to_pool(t_data *data, char *file)
{
	char	**new;

	if (data->capacity == data->length)
	{
		new = ft_memalloc(sizeof(char**) * (data->capacity = ((data->capacity + 1) * 2)));
		if (!new)
			malloc_error(data);
		if (data->names_pool)
			new = ft_memcpy(new, data->names_pool, data->length * sizeof(char**));
		free_names_pool(data);
		data->names_pool = new;
	}
	data->names_pool[data->length] = file;
	data->length++;
}
