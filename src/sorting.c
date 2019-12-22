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

void	swap(t_file *files, int first, int second)
{
	t_file	file;

	file = files->file_data.files[first];
	files->file_data.files[first] = files->file_data.files[second];
	files->file_data.files[second] = file;
}

void	q_sort(t_file *files, int start, int end)
{
	t_file	middle;
	int		left;
	int		right;

	middle = files->file_data.files[(start + end) / 2];
	left = start;
	right = end;
	while(left <= right)
	{
		while (ft_strcmp(files->file_data.files[left].name, middle.name) > 0)
			left++;
		while (ft_strcmp(middle.name, files->file_data.files[right].name) > 0)
			right--;
		if (left <= right)
			swap(files, left++, right--);
	}
	if (right > start)
		q_sort(files, start, right);
	if (left < end)
		q_sort(files, left, end);
}

void	file_sorting(t_file *file)
{
	q_sort(file, 0, file->file_data.length);
}
