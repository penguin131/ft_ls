/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:11:07 by smight            #+#    #+#             */
/*   Updated: 2019/07/26 11:11:09 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    read_folder(char *folder_name, t_data *data)
{
    DIR				*dir;
    struct dirent	*file;
    t_file			file_d;

    if (!(dir = opendir(folder_name)))
		invalid_folder_error(data, folder_name);

    while ((file = readdir(dir)))
	{
    	file_d.name = file->d_name;
    	add_new_file(data, file_d);
		//ft_printf("%s\n", file->d_name);
	}
}

int     main(int c, char **v)
{
    t_data data;

    data.flags = REC_FL;
    read_folder(".", &data);
	//ft_printf("%d: %s\n", c, v[0]);
	return (0);
}
