/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:42:19 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 15:46:54 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_fill_struct(const char *arg, int i, t_param *p)
{
	int index;

	i--;
	while (arg[++i] && (index = is_flag(arg[i])) > -1)
		p->f[index] = 1;
	arg[i] == '*' ? p->w = -2 : 0;
	ft_isdigit(arg[i]) != 0 ? p->w = ft_atoi(&arg[i]) : 0;
	while (arg[i] && p->t == -1)
	{
		if (arg[i - 1] == '.' && arg[i] != '*' && (ft_isdigit(arg[i]))
				&& !(p->l[0]) && !(p->l[1]) && !(p->l[2]) && p->t == -1)
			p->p = ft_atoi(&arg[i]);
		if (arg[i - 1] == '.' && arg[i] != '*' && !(ft_isdigit(arg[i]))
				&& !(p->l[0]) && !(p->l[1]) && !(p->l[2]) && p->t == -1)
			p->p = 0;
		if (arg[i - 1] == '.' && arg[i] == '*' && !(p->l[0]) && !(p->l[1])
				&& !(p->l[2]) && p->t == -1)
			p->p = -2;
		else if (p->t == -1 && (index = is_length(arg[i])) != -1)
			p->l[index] = p->l[index] + 1;
		else if ((index = is_type(arg[i])) >= 0)
			p->t = index;
		i++;
	}
}

char	*ft_create_str(int n, char *src)
{
	char *dst;

	if (n == 0)
		n = ft_strlen(src);
	if (!(dst = ft_strnew(n)))
		return (NULL);
	return (ft_strncpy(dst, src, n));
}

int		ft_add_data2(char *arg, int i, t_param *param)
{
	int n;

	n = i;
	if (arg[i] == '%' && arg[i + 1] != '%' && arg[i + 1] != '\0')
	{
		ft_fill_struct(arg, ++i, param);
		while ((arg[i]) && (is_type(arg[i])) < 0)
			i++;
		param->t == -1 ? i == -1 : i++;
	}
	return (i);
}

int		ft_add_data(char *arg, int i, t_param *param)
{
	int n;

	n = i;
	if (arg[i] == '%' && arg[i + 1] != '%' && arg[i + 1] != '\0')
		i = ft_add_data2(arg, i, param);
	else if (arg[i] == '%' && arg[i + 1] == '\0')
		i++;
	else if (arg[i] == '%' && arg[i + 1] == '%')
	{
		if (!(param->str = ft_create_str(1, &arg[n])))
			return (-1);
		i = i + 2;
	}
	else
	{
		while ((arg[i]) && arg[i] != '%')
			i++;
		if (!(param->str = ft_create_str(i - n, &arg[n])))
			return (-1);
	}
	return (i);
}
