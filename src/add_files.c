/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:22:04 by smight            #+#    #+#             */
/*   Updated: 2019/12/14 15:22:06 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	add_to_reserved_pool(t_info *info, const char *path, const char *name, t_file *file)
{
	t_list	*new_list;
	char	*pool_name;
	size_t	path_len;

	if (!(new_list = ft_memalloc(sizeof(t_list))))
		malloc_error(info);
	path_len = ft_strlen(path) + 1;
	if (!(pool_name = ft_strnew(path_len + ft_strlen(name))))
		malloc_error(info);
	file->path_name = pool_name;
	file->name = pool_name + path_len;
	ft_strcat(pool_name, path);//можно сделать красивее
	ft_strcat(pool_name, "/");
	ft_strcat(pool_name, name);
	new_list->content = (void*)pool_name;
	ft_lstpush(&info->reserved_names_pool, new_list);
	static long int i = 0;
	ft_printf("AaaAAAAAAAAAA----------%d------------AAAAAAAAAAAAAAAaaA\n", i++);
}

void	add_new_filename(t_info *info, const char *path, const char *name, t_file *file)
{
	int i;
	int j;

	i = info->current_index;
	j = 0;
	if (info->pool_len < MAX_POOL_INDEX)//если еще влазит, то пихаю в статический пул. Иначе - пихаю в список
	{
		while (info->names_pool[i][0] && i < MAX_POOL_INDEX)//иду до следующего свободного
			i++;
		if (i == MAX_POOL_INDEX) i = 0;
		while (info->names_pool[i][0] && i < MAX_POOL_INDEX)
			i++;
		file->path_name = info->names_pool[i];
		while (path[j])
		{
			info->names_pool[i][j] = path[j];
			j++;
		}
		info->names_pool[i][j++] = '/';
		file->name = &info->names_pool[i][j];
		while (*name)
			info->names_pool[i][j++] = *name++;
		info->names_pool[i][j] = 0;
		info->pool_len++;
		info->current_index = i;
	}
	else
		add_to_reserved_pool(info, path, name, file);
}

//динамический массив файлов внутри папки
void	add_new_file(t_info *info, t_file *root_file, t_file *new_file)
{
	t_file *new;

	if (root_file->capacity <= root_file->length)
	{
		new = ft_memalloc(sizeof(t_file) *
				(root_file->capacity = ((root_file->capacity + 1) << 1)));
		if (!new)
			malloc_error(info);
		if (root_file->files)
			new = ft_memcpy(new, root_file->files, root_file->length * sizeof(t_file));
		ft_memdel((void**)&root_file->files);
		root_file->files = new;
	}
	root_file->files[root_file->length] = *new_file;
	root_file->length++;
}
