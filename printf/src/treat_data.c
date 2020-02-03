/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treat_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:47:18 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 15:15:59 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	add_to_buff(char *str, int len, t_result *r, int t)
{
	if ((str) && (t == 11 || t == 13 || t == 0 || t == -1))
		ft_colors(str);
    if (len > BUFF_SIZE_P - r->len && r->len > 0)
	{
		r->sum = r->sum + r->len;
		write(r->fd, r->buff, r->len);
		r->len = 0;
		ft_memset(r->buff, '\0', BUFF_SIZE_P);
	}
	if (len > BUFF_SIZE_P)
	{
		r->sum = r->sum + len;
		write(r->fd, str, len);
		ft_strdel(&str);
	}
	if (len < BUFF_SIZE_P)
	{
		ft_memcpy(&r->buff[r->len], str, len);
		r->len = r->len + len;
		ft_strdel(&str);
	}
}

int		ft_fill(char *str, char c, int len)
{
	int i;

	i = -1;
	while (len > 0)
	{
		str[++i] = c;
		len--;
	}
	return (i + 1);
}

int		ft_choose(int a, int b)
{
	int len;

	len = b;
	if (a > b)
		len = a;
	return (len);
}

int		ft_add(t_param *p)
{
	if (((p->t > 10 && p->t < 15) || p->t == 0) && handle_sc(p) == -1)
		return (-1);
	if ((p->t == 3 || p->t == 4) && handle_di(p) == -1)
		return (-1);
	if ((p->t > 4 || p->t < 11) && handle_base(p) == -1)
		return (-1);
	return (0);
}

int		ft_treat_data(t_param *p, t_result *r)
{
	int (*f[15])(t_param*);

	f[0] = ft_c;
	f[1] = ft_f;
	f[2] = ft_f;
	f[3] = ft_d;
	f[4] = ft_d;
	f[5] = ft_o;
	f[6] = ft_u;
	f[7] = ft_x;
	f[8] = ft_xbig;
	f[9] = ft_b;
	f[10] = ft_p;
	f[11] = ft_s;
	f[12] = ft_c;
	f[13] = ft_sbig;
	f[14] = ft_cbig;
	p->t == -1 ? add_to_buff(p->str, (int)ft_strlen(p->str), r, p->t) : 0;
	if (p->t > -1)
	{
		if (f[p->t](p) == -1)
			return (-1);
		add_to_buff(p->str, p->str_len, r, p->t);
	}
	return (0);
}
