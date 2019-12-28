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

#include "ft_ls.h"

void	throw_usage(char c)
{
	ft_printf("ls: illegal option -- %c\n", c);
	ft_printf("usage: ls [-%s] [file ...]\n", FLAG_TYPES);
	exit(0);
}

void	read_flags(t_info *info, int argc, char **argv)
{
	int	i;
	int j;

	i = 1;
	while (i < argc && argv[i][0] == '-')
	{
		j = 0;
		while (argv[i][j] && argv[i][++j])
		{
			if (argv[i][j] == 'L')
				info->flags |= L_FLAG;
			else if (argv[i][j] == 'a')
				info->flags |= A_FLAG;
			else if (argv[i][j] == 'R')
				info->flags |= REC_FL;
			else if (argv[i][j] == 'r')
				info->flags |= R_FLAG;
			else if (argv[i][j] == 't')
				info->flags |= T_FLAG;
			else
				throw_usage(argv[i][j]);
		}
		i++;
	}
}
