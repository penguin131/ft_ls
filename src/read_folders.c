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

short		long_capacity(unsigned long x)
{
	unsigned long p;
	short	i;

	p = 10;
	i = 1;
	while (i < 19)
	{
		if (x < p)
			return (i);
		p = 10 * p;
		i++;
	}
	return 19;
}

int is_hidden_root(t_info *info, const char *name)
{
	if ((info->flags & A_FLAG) != 0)
		return (0);
	return (name[0] == '.' && name[1] != '.' && name[1] != 0);
}

int is_hidden(t_info *info, const char *name)
{
	if ((info->flags & A_FLAG) != 0)
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
			ft_strcmp(root->files[i].name, "..") != 0 &&\
			!S_ISLNK(root->files[i].st_mode))
			read_folder(info, &root->files[i]);
		i++;
	}
}

//тут читаю все параметры из STAT
int		read_file_input(t_info *info, t_file *input_file, struct dirent *read_file)
{
	struct stat		buff;
	t_file			new_file;
	struct passwd	*pw;
	struct group	*gr;

	ft_bzero(&new_file, sizeof(t_file));
	add_new_filename(info, input_file->path_name, read_file->d_name, &new_file);
	if (lstat(new_file.path_name, &buff) == -1)
		return (-1);
	new_file.is_folder = S_ISDIR(buff.st_mode) ? 1 : 0;
	new_file.st_mode = buff.st_mode;
	new_file.size = buff.st_size;
    new_file.n_link = buff.st_nlink;
    input_file->total_n_link += buff.st_blocks;
    if (long_capacity(buff.st_nlink) > input_file->max_n_link_len)
    	input_file->max_n_link_len = long_capacity(buff.st_nlink);
    if (long_capacity(new_file.size) > input_file->max_size_len)
    	input_file->max_size_len = long_capacity(new_file.size);
	new_file.time = buff.st_atime;
	pw = getpwuid(buff.st_uid);
	gr = getgrgid(buff.st_gid);
	if ( (pw && !(new_file.username = ft_strdup(pw->pw_name))) ||
		(gr && !(new_file.year = ft_strdup(gr->gr_name))))
		malloc_error(info);
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
		if (is_hidden(info, read_file->d_name))
			continue;
		read_file_input(info, input_file, read_file);
	}
	closedir(dir);
    file_sorting(info, input_file);
	print_files(info, input_file);
	if ((info->flags & REC_FL) != 0)
		read_nested_folders(info, input_file);
	free_data(info, input_file);
}
