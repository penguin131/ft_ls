/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:01:50 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 15:15:14 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		handle_sc(t_param *p)
{
	char	*s;
	int		i;
	int		j;

	j = -1;
	i = 0;
	if (p->str_len > p->w)
		return (0);
	if (!(s = ft_strnew(p->w)))
		return (-1);
	if (p->w > p->str_len && p->f[1] == 0)
		i = i + ft_fill(s, ' ', p->w - p->str_len);
	while (p->str[++j])
	{
		s[i] = p->str[j];
		i++;
	}
	if (p->w > p->str_len && p->f[1] != 0)
		i = i + ft_fill(&s[i], ' ', p->w - p->str_len);
	ft_strdel(&(p->str));
	p->str_len = p->w;
	p->str = s;
	return (0);
}

void	ft_handle_di2(char *s, int i, int len_tot, t_param *p)
{
	int j;
	int len_prec;

	j = -1;
	len_prec = ft_choose(p->p, p->str_len);
	if (p->w > p->str_len + p->f[0] && p->f[1] == 0 && p->f[4] == 1 &&\
	p->p == -1)
		i = i + ft_fill(&s[i], '0', len_tot - p->str_len - p->f[0]);
	if (p->p > p->str_len)
		i = i + ft_fill(&s[i], '0', p->p - p->str_len);
	while (p->str[++j])
	{
		s[i] = p->str[j];
		i++;
	}
	if (p->w > len_prec + p->f[0] && p->f[1] != 0)
		i = i + ft_fill(&s[i], ' ', p->w - len_prec - p->f[0]);
	ft_strdel(&(p->str));
	p->str_len = len_tot;
	p->str = s;
}

int		handle_di(t_param *p)
{
	char	*s;
	int		i;
	int		len_tot;
	int		len_prec;

	i = 0;
	if (p->f[2] == 1 && p->sign == '+' && p->f[0] == 0)
	{
		p->sign = ' ';
		p->f[0] = 1;
	}
	len_prec = ft_choose(p->p, p->str_len);
	len_tot = ft_choose(p->w, len_prec + p->f[0]);
	if (len_tot == p->str_len)
		return (0);
	if (!(s = ft_strnew(len_tot)))
		return (-1);
	if (p->w > p->str_len + p->f[0] && p->f[1] == 0 && (p->f[4] == 0 ||\
	(p->f[4] != 0 && p->p != -1)))
		i = i + ft_fill(&s[i], ' ', len_tot - len_prec - p->f[0]);
	if (p->f[0] == 1)
		i = i + ft_fill(&s[i], p->sign, 1);
	ft_handle_di2(s, i, len_tot, p);
	return (0);
}

void	ft_handle_base2(char *s, int i, int len_tot, t_param *p)
{
	int j;
	int len_prec;

	j = -1;
	len_prec = ft_choose(p->p, p->str_len);
	if (p->f[3] == 2 && p->t == 8)
		i = i + ft_fill(&s[i], 'X', 1);
	if (p->w > p->str_len + p->f[3] && p->f[1] == 0 && p->f[4] == 1 &&\
	p->p == -1)
		i = i + ft_fill(&s[i], '0', len_tot - p->str_len - p->f[3]);
	if (p->p > p->str_len)
		i = i + ft_fill(&s[i], '0', p->p - p->str_len);
	while (p->str[++j])
	{
		s[i] = p->str[j];
		i++;
	}
	if (p->w > p->str_len && p->f[1] != 0)
		i = i + ft_fill(&s[i], ' ', p->w - len_prec - p->f[3]);
	ft_strdel(&(p->str));
	p->str_len = len_tot;
	p->str = s;
}

int		handle_base(t_param *p)
{
	char	*s;
	int		i;
	int		len_tot;
	int		len_prec;

	i = 0;
	(p->f[3] == 1 && (p->t == 7 || p->t == 8 || p->t == 10)) ? p->f[3] = 2 : 0;
	(p->t == 6 || p->t == 9) ? p->f[3] = 0 : 0;
	(p->f[3] == 1 && p->t == 5 && p->p > p->str_len) ? p->f[3] = 0 : 0;
	len_prec = ft_choose(p->p, p->str_len);
	len_tot = ft_choose(p->w, len_prec + p->f[3]);
	if (len_tot == p->str_len)
		return (0);
	if (!(s = ft_strnew(len_tot)))
		return (-1);
	if (p->w > p->str_len + p->f[3] && p->f[1] == 0 && (p->f[4] == 0 ||\
	(p->f[4] != 0 && p->p != -1)))
		i = i + ft_fill(&s[i], ' ', len_tot - len_prec - p->f[3]);
	if (p->f[3] != 0)
		i = i + ft_fill(&s[i], '0', 1);
	if (p->f[3] == 2 && (p->t == 7 || p->t == 10))
		i = i + ft_fill(&s[i], 'x', 1);
	ft_handle_base2(s, i, len_tot, p);
	return (0);
}
