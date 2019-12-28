/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_params.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:50:57 by smight            #+#    #+#             */
/*   Updated: 2019/12/22 14:50:58 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	read_nested_folders(t_info *info, t_file *root)
{
	int	i;

	i = 0;
	while (i < root->length)
	{
		if (root->files[i].is_folder == 1 &&\
			ft_strcmp(root->files[i].name, ".") != 0 &&\
			ft_strcmp(root->files[i].name, "..") != 0)
			read_folder(info, &root->files[i]);
		i++;
	}
}

int		read_file_input(t_info *info, t_file *input_file, t_file new_file, struct dirent *read_file)
{
	struct stat		buff;

	ft_strcat(new_file.path_name, read_file->d_name);
	ft_strcpy(new_file.name, read_file->d_name);
	if (stat(new_file.path_name, &buff) == -1)
		return (-1);
	new_file.is_folder = S_ISDIR(buff.st_mode) ? 1 : 0;
	add_new_file(info, input_file, new_file);
	return (1);
}

void    read_folder(t_info *info, t_file *input_file)
{
	DIR				*dir;
	struct dirent	*read_file;
	t_file			temp_file;

	if (!(dir = opendir(input_file->path_name)))
		return;
	ft_bzero(&temp_file, sizeof(t_file));
	ft_strcpy(temp_file.path, input_file->path_name);
	ft_strcpy(temp_file.path_name, input_file->path_name);
	ft_strcat(temp_file.path_name, "/");
	while ((read_file = readdir(dir)))
	{
		if (read_file_input(info, input_file, temp_file, read_file) == -1)
			continue;
	}
	closedir(dir);
	file_sorting(input_file);
	print_files(info, input_file);
	if (info->is_many_folders == 1)
		read_nested_folders(info, input_file);
}
