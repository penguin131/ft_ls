/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_flags.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/27 14:52:01 by smight            #+#    #+#             */
/*   Updated: 2019/06/03 13:53:40 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strfjoin(char const *s1, char const *s2)
{
	char	*buff;

	if (!s1 && !s2)
		return (NULL);
	else if (s1 && !s2)
	{
		if ((buff = ft_strnew(ft_strlen(s1))))
			buff = ft_strcpy(buff, s1);
	}
	else if (s2 && !s1)
	{
		if ((buff = ft_strnew(ft_strlen(s2))))
			buff = ft_strcpy(buff, s2);
	}
	else
	{
		if ((buff = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		{
			ft_strcpy(buff, s1);
			ft_strcat(buff, s2);
		}
	}
	ft_memdel((void**)&s1);
	ft_memdel((void**)&s2);
	return (buff);
}

int		ft_specific_values(union u_double d, t_param *p)
{
	char *res;

	if (!(p->str = ft_strnew(3)))
		return (-1);
	if (d.ld != d.ld)
		p->str = ft_strcpy(p->str, p->t == T_F ? "nan" : "NAN");
	else if (d.ld == 1.0 / 0.0 || d.ld == -1.0 / 0.0)
		p->str = ft_strcpy(p->str, p->t == T_F ? "inf" : "INF");
	if (p->w > 3 || ((p->f[0] || p->f[2]) && p->str[0] == 'i'))
	{
		res = ft_strnew(p->w > 3 ? p->w : 4);
		ft_memset(res, ' ', (p->w > 3 ? p->w : 4));
		if (p->f[0] && !p->f[1] && p->str[0] == 'i')
			res[p->w > 3 ? p->w - 4 : 0] = p->sign;
		else if (p->f[0] && p->f[1] && (p->str[0] == 'i' || p->str[0] == 'I'))
			res[0] = p->sign;
		if (p->f[1])
			ft_memcpy(res + (p->f[0] && (p->str[0] == 'i'
			|| p->str[0] == 'I') ? 1 : 0), p->str, 3);
		else
			ft_memcpy(res + (p->w > 3 ? p->w - 3 : 1), p->str, 3);
		ft_strdel(&p->str);
		p->str = res;
	}
	return ((p->str_len = ft_strlen(p->str)) > 0 ? 0 : -1);
}

int		ft_check_grow(char *s)
{
	while (s && *s)
		if (*s++ > '0')
			return (1);
	return (0);
}

char	*ft_rounding(char *res, char *s)
{
	int		i;
	int		mark;

	i = ft_strlen(res);
	mark = ft_check_grow(s + i + 1) && s[i] == '5' ? 1 : 0;
	if (s[i] >= '5')
		while (--i >= 0)
		{
			if (res[i] == '.')
				continue ;
			if (s[i + 1] == '5' && !mark)
			{
				(res[i] - '0') % 2 > 0 ? res[i]++ : 0;
				break ;
			}
			if (res[i] != '9')
			{
				res[i]++;
				break ;
			}
			res[i] = '0';
		}
	return (res);
}

char	*ft_upgrade(t_param *p, char *s)
{
	char	*res;
	size_t	len;

	len = 0;
	if (!s)
		return (NULL);
	if (s[ft_strlen(s) - 1] == '.')
		s = ft_strfjoin(s, ft_memset(ft_strnew(p->w), 48, p->w));
	while (s[len + 1] != '.')
		len++;
	len += 2 + p->p;
	res = ft_memcpy(ft_memset(ft_strnew(len), '0', len), s,
			ft_strlen(s) > len ? len : ft_strlen(s));
	if (!res || !s)
		return (NULL);
	res = ft_rounding(res, s);
	if (!res)
		return (NULL);
	ft_strdel(&s);
	p->str_len = ft_strlen(res);
	return (res);
}
