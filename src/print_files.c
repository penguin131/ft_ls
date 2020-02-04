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

/*
 * 1.Ищу ширину столбца по максимальной длине имени
 * 2.Считаю кол-во столбцов ws_col / ширину столбца
 * 3.Считаю кол-во линий = кол-во файлов / кол-во столбцов,
 *   если есть остаток от деления то + 1
 */

int 	get_column_width(t_file *root_file)
{
	int	i;
	int max;

	i = 0;
	max = 0;
	while (i < root_file->length)
	{
		if (root_file->files[i].name_len > max)
			max = root_file->files[i].name_len;
		i++;
	}
	return (max + 1);
}

int		get_column_count(int col_width, struct winsize *w_size)
{
	return (w_size->ws_col / col_width);
}

int		get_lines_count(int files_cnt, int columns_cnt)
{
	int cnt;

	cnt = files_cnt / columns_cnt;
	if (files_cnt % columns_cnt > 0)
		cnt += 1;
	return (cnt);
}

void	print_simple(t_file *root_file, struct winsize *w_size)
{
	int col_width;
	int col_cnt;
	int lines_cnt;
	int i;
	int j;

	col_width = get_column_width(root_file);
	col_cnt = get_column_count(col_width, w_size);
	lines_cnt = get_lines_count(root_file->length, col_cnt);
	i = 0;
	while (i < lines_cnt)
	{
		j = i;
		while (j < root_file->length)
		{
			ft_printf("%-*s", col_width, root_file->files[j].name);
			j += lines_cnt;
		}
		ft_printf("\n");
		i++;
	}
}

void	print_files(t_info *info, t_file *file)
{
	struct winsize	w_size;

	if (info->mock_folder.length > 1 || (info->flags & REC_FL) != 0)
    {
	    if (info->is_not_first != 0)
            ft_printf("\n");
        if (info->mock_folder.length > 1 || info->is_not_first != 0)
        	ft_printf("%s:\n", file->path_name);
		info->is_not_first = 1;
    }
	if ((info->flags & L_FLAG) != 0)
	    print_l(info, file);
	else
	{
		ioctl(STDOUT_FILENO, TIOCGWINSZ, &w_size);//ширина экрана, ws_col - ширина
		print_simple(file, &w_size);
	}
}

void    print_invalid_folders(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->mock_folder.length)
	{
		if (info->mock_folder.files[i].is_error == 1)
			ft_printf("ls: %s: No such file or directory\n", info->mock_folder.files[i].name);
		i++;
	}
}
