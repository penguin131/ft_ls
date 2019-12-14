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

void    invalid_folder_error(t_data *data, char *folder_name)
{
    ft_printf("ls: %s: No such file or directory", folder_name);
    ft_memdel((void**)data->files);
    exit(0);
}

void	malloc_error(t_data *data)
{
	ft_memdel((void**)data->files);
	exit(0);
}
