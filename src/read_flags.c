/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_flags.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/28 16:38:01 by smight            #+#    #+#             */
/*   Updated: 2019/12/28 16:38:03 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "ft_ls.h"

void	throw_usage(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-%s] [file ...]\n", FLAG_TYPES);
	exit(0);
}

void	read_flags(t_info *info, int argc, char **argv)
{
	int j;

	info->start = 1;
	while (info->start < argc && argv[info->start][0] == '-')
	{
		j = 0;
		while (argv[info->start][j] && argv[info->start][++j])
		{
			if (argv[info->start][j] == 'l')
				info->flags |= L_FLAG;
			else if (argv[info->start][j] == 'a')
				info->flags |= A_FLAG;
			else if (argv[info->start][j] == 'R')
				info->flags |= REC_FL;
			else if (argv[info->start][j] == 'r')
				info->flags |= R_FLAG;
			else if (argv[info->start][j] == 't')
				info->flags |= T_FLAG;
			else
				throw_usage(argv[info->start][j]);
		}
		(info->start)++;
	}
//	info->start = 1;
}

char	*get_string_time(t_info *info, time_t *c_time)
{
	char	*result;
	char	*str;
	time_t	now_clock;

	str = ctime(c_time);
	now_clock = time(0);
	if ((info->flags & T_FLAG) != 0)
		result = ft_strsub(str, 4, ft_strlen(str + 4) - 1);
	else
	{
		result = ft_strsub(str, 4, 12);
		if (now_clock < *c_time || now_clock - *c_time > 15724800)
			ft_memcpy(result + 7, str + 19, 5);
	}
	return (result);
}
