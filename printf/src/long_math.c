/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_math.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/24 12:57:43 by smight            #+#    #+#             */
/*   Updated: 2019/05/24 12:57:45 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_number	ft_new_number(char n)
{
	t_number	res;

	res.cap = MAX_INDEX;
	ft_memset(res.num, 0, MAX_LEN + 1);
	res.num[MAX_INDEX] = n;
	return (res);
}

void		ft_magic_sum(t_number *n1, t_number n2)
{
	size_t i;
	size_t extr;

	i = MAX_LEN;
	extr = 0;
	while (--i >= n1->cap || i >= n2.cap)
	{
		if ((n1->num[i] += n2.num[i] + extr) > 9)
		{
			n1->num[i] -= 10;
			extr = 1;
		}
		else
			extr = 0;
	}
	n1->cap = n1->cap <= n2.cap ? n1->cap : n2.cap;
	if (extr > 0)
	{
		n1->cap--;
		n1->num[i] = extr;
	}
}

void		ft_magic_mult_n(t_number *r, t_number n1, char n2, size_t shift)
{
	size_t old;
	size_t new;
	size_t i;

	old = 0;
	i = MAX_INDEX - shift;
	while (i <= MAX_INDEX)
		r->num[i++] = 0;
	i = MAX_LEN;
	while (--i >= n1.cap)
	{
		new = (n1.num[i] * n2 + old) / 10;
		r->num[i - shift] = (n1.num[i] * n2 + old) % 10;
		old = new;
	}
	r->cap = n1.cap - shift;
	if (old > 0)
	{
		r->cap--;
		r->num[i - shift] = old;
	}
}

t_number	ft_magic_mult(t_number n1, t_number n2)
{
	t_number	l1;
	t_number	l2;
	size_t		i;
	size_t		shift;

	l1 = ft_new_number(0);
	l2 = ft_new_number(0);
	i = MAX_LEN;
	shift = 0;
	while (--i >= n2.cap)
	{
		ft_magic_mult_n(&l2, n1, n2.num[i], shift++);
		ft_magic_sum(&l1, l2);
	}
	return (l1);
}

t_number	ft_magic_power(size_t pow, t_number n)
{
	size_t		i;
	t_number	res;

	i = 0;
	res = ft_new_number(n.num[MAX_INDEX]);
	while (++i < pow)
	{
		res = ft_magic_mult(res, n);
	}
	return (res);
}
