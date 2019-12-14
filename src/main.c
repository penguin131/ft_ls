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

char	*get_full_name(char *dir, char *filename)
{
	char	*result;
	size_t	dir_len;
	size_t	filename_len;

	dir_len = ft_strlen(dir);
	filename_len = ft_strlen(filename);
	if (!(result = ft_memalloc(dir_len + filename_len + 1)))
		malloc_error();
	ft_memcpy(result, dir, dir_len);
	ft_strcat(result, "/");
	ft_strcat(result, filename);
	return result;
}

void	read_nested_folders(t_data *data)
{
	int	i;

	i = 0;
	while (i < data.length)
		if (data.files[i].is_folder == 1)
			read_folder(data.files[i].name);
}

void    read_folder(t_data *data, char *folder_name)
{
    DIR				*dir;
    struct dirent	*file;
	struct stat		buff;
	t_file			file_d;

    if (!(dir = opendir(folder_name)))
		invalid_folder_error(data, folder_name);
    while ((file = readdir(dir)))
	{
    	if (!(file_d.name = get_full_name(folder_name, file->d_name)))
    		malloc_error(data);
    	add_new_name_to_pool(data, file_d.name);
    	if (stat(file_d.name, &buff) == -1)
			continue;
		file_d.is_folder = S_ISDIR(buff.st_mode) ? 1 : 0;
	}
	print_files(&data);
	read_nested_folders(data);
}

int     main(int c, char **v)
{
	t_data	data;

	data.names_pool = NULL;

    read_folder("..");
	return (0);
}
