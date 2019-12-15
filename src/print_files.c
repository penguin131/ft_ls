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

void	print_files(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->length)
	{
		ft_printf("%35s%10c\n", data->files[i].name, data->files[i].is_folder ? '1' : '0');
		i++;
	}
}
