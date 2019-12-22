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

void	print_files(t_file *file)
{
	int	i;

	i = 0;
	ft_printf("%s:\n", file->path);
	while (i < file->file_data.length)
	{
		ft_printf("%35s%10c\n", file->file_data.files[i].name, file->file_data.files[i].is_folder ? '1' : '0');
		i++;
	}
	ft_printf("\n");
}
