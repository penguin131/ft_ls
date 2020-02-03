/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   upgrade2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/02 12:07:02 by smight            #+#    #+#             */
/*   Updated: 2019/06/03 13:52:38 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_sign(t_param *p)
{
	char	*res;
	size_t	i;

	if (p->f[2] || p->sign == '-' || p->f[0])
	{
		i = 0;
		while (p->str[i] == ' ' && p->str[i + 1] == ' ')
			i++;
		if ((p->str[i] == '0' && p->str[i + 1] != '.') || p->str[i] == ' ')
		{
			p->str[i] = (p->f[0] || p->sign == '-') ? p->sign : ' ';
			return (1);
		}
		res = ft_strnew(p->str_len + 1);
		if (!res)
			return (-1);
		ft_memcpy(res + 1, p->str, p->str_len);
		!p->f[0] && p->sign != '-' ? p->sign = ' ' : 0;
		res[0] = p->sign;
		ft_strdel(&p->str);
		p->str = res;
		p->str_len = ft_strlen(p->str);
	}
	return (1);
}

int		ft_width(t_param *p)
{
	char	*res;

	if (p->w > p->str_len)
	{
		res = ft_strnew(p->w);
		if (!res)
			return (-1);
		ft_memset(res, p->f[4] ? '0' : ' ', p->w);
		if (p->f[1])
			ft_memcpy(res + (p->f[0] || p->f[2] ? 1 : 0), p->str, p->str_len);
		else
			ft_memcpy(res + p->w - p->str_len, p->str, p->str_len);
		ft_strdel(&p->str);
		p->str = res;
		p->str_len = ft_strlen(p->str);
	}
	return (1);
}
