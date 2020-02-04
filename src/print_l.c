/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_l.c                                      :+:      :+:    :+:       */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/14 15:58:11 by smight            #+#    #+#             */
/*   Updated: 2019/12/14 15:58:12 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void    print_file_type(unsigned long st_mode)
{
	if (S_ISBLK(st_mode))
		ft_printf("b");
	else if (S_ISCHR(st_mode))
		ft_printf("c");
	else if (S_ISDIR(st_mode))
		ft_printf("d");
	else if (S_ISFIFO(st_mode))
		ft_printf("p");
	else if (S_ISLNK(st_mode))
		ft_printf("l");
	else if (S_ISSOCK(st_mode))
		ft_printf("s");
	else
		ft_printf("-");
}

void    print_file_chmod(unsigned long st_mode)
{
	char	*str;
	int		i;
	short	mask;

	i = 8;
	mask = 1;
	str = ft_strdup("rwxrwxrwx");
	while (i > 0)
	{
		if ((st_mode & mask) == 0)
			str[i] = '-';
		mask = mask << 1;
		i--;
	}
	ft_printf("%s", str);
}

/*
 * numeric time to string
 */
void    print_time(t_info *info, time_t time_p)
{
	char	*answer;
	char	*str;
	time_t	now_clock;

	str = ctime(&time_p);
	now_clock = time(0);
	if ((info->flags & T_FLAG) != 0)
		answer = ft_strsub(str, 4, ft_strlen(str + 4) - 1);
	else
	{
		answer = ft_strsub(str, 4, 12);
		if (now_clock < time_p || now_clock - time_p > 15724800)
			ft_memcpy(answer + 7, str + 19, 5);
	}
	if (!answer)
		malloc_error(info);
	ft_printf("%s", answer);
	ft_memdel((void**)&answer);
}

void	print_link(char *pathname)
{
	size_t	len;
	char	buff[MAX_PATH_LEN];

	if (readlink(pathname, NULL, 0) == -1)
		return ;
	ft_bzero(&buff, MAX_PATH_LEN);
	len = readlink(pathname, buff, MAX_PATH_LEN);
	if (len > 0)
		ft_printf(" -> %s", buff);
}

void    print_l(t_info *info, t_file *file)
{
	int	i;

	i = 0;
	if (file->length > 0)
		ft_printf("total %d\n", file->total_n_link);
	while (i < file->length)
	{
		print_file_type(file->files[i].st_mode);
		print_file_chmod(file->files[i].st_mode);
		if ((S_ISLNK(file->files[i].st_mode) && listxattr(file->files[i].path_name, NULL, 0, XATTR_NOFOLLOW) > 0) ||
			(listxattr(file->files[i].path_name, NULL, 0, 0) > 0))
			ft_printf("@");
		else
			ft_printf(" ");
		ft_printf("%*d %s  %s", file->max_n_link_len + 1, file->files[i].n_link, file->files[i].username, file->files[i].year);
		ft_printf(" %*d ", file->max_size_len + 1, file->files[i].size);
		print_time(info, file->files[i].time);
		ft_printf(" %s", file->files[i].name);
		if (S_ISLNK(file->files[i].st_mode))
			print_link(file->files[i].path_name);
		ft_printf("\n");
		i++;
	}
}
