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

void	free_names_pool(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->length)
	{
		ft_memdel((void**)&data->names_pool[i]);
		i++;
	}
	ft_memdel((void**)&data->names_pool);
}

void    invalid_folder_error(t_data *data, char *folder_name)
{
    ft_printf("ls: %s: No such file or directory", folder_name);
    free_names_pool(data);
    exit(0);
}

void	malloc_error(t_data *data)
{
	free_names_pool(data);
	exit(0);
}
