/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_cs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:51:44 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 13:07:44 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_cut_str(t_param *param)
{
	char *str_new;

	if (!(str_new = ft_strnew(param->p)))
		return (NULL);
	str_new = ft_strncpy(str_new, param->str, param->p);
	ft_strdel(&(param->str));
	param->str_len = param->p;
	return (str_new);
}

int		ft_c(t_param *p)
{
	int nb;

	if (p->l[0] != 0 && ft_cbig(p) == -1)
		return (-1);
	else
	{
		p->str_len = 1;
		if (p->t == 0)
			nb = '%';
		else
			nb = va_arg(p->ar, int);
		if (!(p->str = ft_strnew(1)))
			return (-1);
		p->str[0] = (unsigned char)nb;
		if (p->w > -1 && ft_add(p) == -1)
			return (-1);
	}
	return (0);
}

int		ft_cbig(t_param *p)
{
	int nb;

	p->str_len = 1;
	if (p->t == 0)
		nb = '%';
	else
		nb = va_arg(p->ar, int);
	if (!(p->str = ft_strnew(1)))
		return (-1);
	p->str[0] = (wchar_t)nb;
	if (p->w > -1 && ft_add(p) == -1)
		return (-1);
	return (0);
}

int		ft_s(t_param *p)
{
	char *str;

	str = va_arg(p->ar, char*);
	if (!str)
		str = "(null)";
	if (!(p->str = ft_strdup(str)))
		return (-1);
	p->str_len = ft_strlen(p->str);
	if (p->p > -1 || p->w > -1)
	{
		if (p->p > -1 && p->p < p->str_len && !(p->str = ft_cut_str(p)))
			return (-1);
		p->p = -1;
		if (p->w > -1 && p->str_len < p->w && ft_add(p) == -1)
			return (-1);
	}
	return (0);
}

int		ft_sbig(t_param *p)
{
	char *str;

	str = (char*)va_arg(p->ar, wchar_t*);
	if (!str)
		str = "(null)";
	if (!(p->str = ft_strdup(str)))
		return (-1);
	p->str_len = ft_strlen(p->str);
	if (p->p > -1 || p->w > -1)
	{
		if (p->p > -1 && p->p < p->str_len && !(p->str = ft_cut_str(p)))
			return (-1);
		if (p->w > -1 && p->str_len < p->w && ft_add(p) == -1)
			return (-1);
	}
	return (0);
}
