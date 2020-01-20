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

int is_hidden_root(const char *name)
{
	if ((flags & A_FLAG) != 0)
		return (0);
	return (name[0] == '.' && name[1] != '.' && name[1] != 0);
}

int is_hidden(const char *name)
{
	if ((flags & A_FLAG) != 0)
		return (0);
	return (name[0] == '.');
}

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

int		read_file_input(t_info *info, t_file *input_file, struct dirent *read_file)
{
	struct stat		buff;
	t_file			new_file;

	ft_bzero(&new_file, sizeof(t_file));
	add_new_filename(info, input_file->path_name, read_file->d_name, &new_file);
	if (stat(new_file.path_name, &buff) == -1)
		return (-1);
	new_file.is_folder = S_ISDIR(buff.st_mode) ? 1 : 0;
	add_new_file(info, input_file, &new_file);//добавляю новый файл в динамический массив
	return (1);
}

void    read_folder(t_info *info, t_file *input_file)
{
	DIR				*dir;
	struct dirent	*read_file;

	if (!input_file->path_name || !(dir = opendir(input_file->path_name)))
		return;
	//в цикле прохожусь по всем файлам в данной директории
	while ((read_file = readdir(dir)))
	{
		//если не надо читать скрытые файлы(начинающиеся с точки), то иду дальше
		if (is_hidden(read_file->d_name))
			continue;
		if (read_file_input(info, input_file, read_file) == -1)
			continue;
	}
	closedir(dir);
	if ((flags & REC_FL) != 0)
		read_nested_folders(info, input_file);
	free_data(info, input_file);
}
