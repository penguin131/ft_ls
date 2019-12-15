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

//void	read_nested_folders(t_data *data)
//{
//	int	i;
//
//	i = 0;
//	while (i < data.length)
//		if (data.files[i].is_folder == 1)
//			read_folder(data.files[i].name);
//}

int		read_file_input(t_file *input_file, t_file new_file, struct dirent *read_file)
{
	struct stat		buff;

	ft_strcat(new_file.path_name, read_file->d_name);
	ft_strcpy(new_file.name, read_file->d_name);
	if (stat(new_file.path_name, &buff) == -1)
		return (-1);
	new_file.is_folder = S_ISDIR(buff.st_mode) ? 1 : 0;
	add_new_file(input_file, new_file);
	return 1;
}

//передаю сюда уже созданную data,
void    read_folder(t_file *input_file)
{
	DIR				*dir;
	struct dirent	*read_file;
	t_file			new_file;

	if (!(dir = opendir(input_file->path_name)))
		invalid_folder_error(input_file->name);
	new_file.file_data.files = NULL;
	ft_strcpy(new_file.path, input_file->path_name);
	ft_strcpy(new_file.path_name, input_file->path_name);
	ft_strcat(new_file.path_name, "/");
	while ((read_file = readdir(dir)))
	{
		if (read_file_input(input_file, new_file, read_file) == -1)
			continue;
	}
	print_files(&input_file->file_data);
//	read_nested_folders(data);
}

int     main(int c, char **v)
{
	flags = 0;
	root_file = ft_memalloc(sizeof(t_file));
	ft_strcpy(root_file->path_name, "../.");
	ft_strcpy(root_file->path, "..");
	ft_strcpy(root_file->name, ".");

	read_folder(root_file);
	return (0);
}