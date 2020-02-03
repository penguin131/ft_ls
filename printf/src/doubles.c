/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doubles.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/19 16:09:37 by smight            #+#    #+#             */
/*   Updated: 2019/06/03 13:52:17 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_result_str(t_number input, int pow, short bit)
{
	char	*res;
	size_t	i;

	i = 0;
	while (i < MAX_LEN)
		input.num[i++] += '0';
	i = 0;
	while (input.num[i] == '0')
		i++;
	if (bit)
		i = MAX_LEN - 64 - pow;
	res = ft_strdup(&input.num[i]);
	return (res);
}

char	*ft_int_part(int pow, unsigned long int mant, int exp)
{
	t_number	res;
	t_number	add;

	res = ft_new_number(0);
	add = ft_new_number(1);
	if (exp <= 0)
		return (ft_memset(ft_strnew(2), '0', 1));
	while (pow-- > 0)
		ft_magic_sum(&add, add);
	while (mant > 0)
	{
		if (mant & 1)
			ft_magic_sum(&res, add);
		ft_magic_sum(&add, add);
		mant >>= 1;
	}
	return (ft_result_str(res, pow, 0));
}

char	*ft_fract_part(int pow, unsigned long int mant)
{
	int			i;
	t_number	five;
	t_number	two;
	t_number	res;

	res = ft_new_number(0);
	five = ft_new_number(5);
	two = ft_new_number(2);
	five = ft_magic_power(64 + pow, five);
	i = 0;
	while (++i <= 64)
	{
		if (mant & 0x8000000000000000)
			ft_magic_sum(&res, ft_magic_mult(five,
					ft_magic_power(64 - i + (pow == 0 ? 0 : 1), two)));
		mant <<= 1;
	}
	return (ft_result_str(res, pow, 1));
}

int		ft_check_double(union u_double *d, t_param *p)
{
	p->p = p->p == -1 ? 6 : p->p;
	if (d->s_parts.expon == 0 && d->s_parts.mant == 0)
	{
		if (d->s_parts.sign == 1)
			p->sign = '-';
	}
	else if (d->ld < 0)
		p->sign = '-';
	if (d->ld != d->ld || d->ld == 1.0 / 0.0 || d->ld == -1.0 / 0.0)
		return (1);
	return (0);
}

int		ft_f(t_param *p)
{
	union u_double		d;
	int					exp;
	int					pow;
	unsigned long int	mant;

	d.ld = (p->l[L_BIGL] == 1 ? va_arg(p->ar,
			long double) : va_arg(p->ar, double));
	if (ft_check_double(&d, p))
		return (ft_specific_values(d, p));
	exp = d.s_parts.expon == 0 ? 0 : d.s_parts.expon - 16382;
	pow = 0;
	if (exp > 0 && exp < 65)
		mant = d.s_parts.mant >> (64 - exp);
	else
		pow = exp <= 0 ? -exp + 1 : exp - 64;
	p->str = ft_int_part(pow, exp > 64 ? d.s_parts.mant : mant, exp);
	if (p->p > 0 || p->f[F_SHARP] == 1)
		p->str = ft_strfjoin(p->str, ft_memset(ft_strnew(1), '.', 1));
	if (p->p > 0 && exp < 64)
		p->str = ft_strfjoin(p->str, ft_fract_part(pow, exp <= 0 ?
		d.s_parts.mant : d.s_parts.mant << exp));
	p->str = ft_upgrade(p, p->str);
	return (ft_width(p) | ft_sign(p));
}
