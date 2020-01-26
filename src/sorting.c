/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 14:02:27 by smight            #+#    #+#             */
/*   Updated: 2019/12/22 14:02:28 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int files_comparer(t_info *info, t_file file1, t_file file2)
{
	return (info->flags & R_FLAG) == 0 ? ft_strcmp(file1.name, file2.name) < 0 : ft_strcmp(file1.name, file2.name) > 0;
}

void	swap(t_file *file, int first, int second)
{
	t_file	tmp;

	ft_bzero(&tmp, sizeof(t_file));
	ft_memcpy(&tmp, &file->files[first], sizeof(t_file));
	ft_memcpy(&file->files[first], &file->files[second], sizeof(t_file));
	ft_memcpy(&file->files[second], &tmp, sizeof(t_file));
}

void q_sort(t_info *info, t_file *files, int start, int end)
{
	t_file	middle;
	int		left;
	int		right;

	middle = files->files[(start + end) >> 1];
	left = start;
	right = end;
	while(left <= right)
	{
		while (files_comparer(info, files->files[left], middle))
			left++;
		while (files_comparer(info, middle, files->files[right]))
			right--;
		if (left <= right)
			swap(files, left++, right--);
	}
	if (right > start)
        q_sort(info, files, start, right);
	if (left < end)
        q_sort(info, files, left, end);
}

void file_sorting(t_info *info, t_file *file)
{
	if (file->length > 1)
        q_sort(info, file, 0, file->length - 1);
}
