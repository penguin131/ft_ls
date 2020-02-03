/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_common.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:05:04 by rsumner           #+#    #+#             */
/*   Updated: 2019/05/31 11:10:36 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned long long int	get_unsig_nb(t_param *param)
{
	unsigned long long int nb;

	if (param->l[0] == 1)
		nb = va_arg(param->ar, unsigned long int);
	else if (param->l[0] == 2)
		nb = va_arg(param->ar, unsigned long long int);
	else if (param->l[1] == 1)
		nb = (unsigned short int)va_arg(param->ar, unsigned int);
	else if (param->l[1] == 2)
		nb = (unsigned char)va_arg(param->ar, unsigned int);
	else if (param->l[0] == 3)
		nb = va_arg(param->ar, unsigned int);
	else if (param->l[3] == 1)
		nb = va_arg(param->ar, uintmax_t);
	else if (param->l[4] == 1)
		nb = va_arg(param->ar, size_t);
	else
		nb = va_arg(param->ar, unsigned int);
	return (nb);
}

long long int			get_sig_nb(t_param *param)
{
	long long int nb;

	if (param->l[0] == 1)
		nb = va_arg(param->ar, long int);
	else if (param->l[0] == 2)
		nb = va_arg(param->ar, long long int);
	else if (param->l[1] == 1)
		nb = (short int)va_arg(param->ar, int);
	else if (param->l[1] == 2)
		nb = (char)va_arg(param->ar, int);
	else if (param->l[0] == 3)
		nb = va_arg(param->ar, int);
	else if (param->l[3] == 1)
		nb = va_arg(param->ar, intmax_t);
	else if (param->l[4] == 1)
		nb = va_arg(param->ar, size_t);
	else
		nb = va_arg(param->ar, int);
	return (nb);
}

int						ft_find_len(unsigned long long int nb, int base)
{
	int len;

	len = 0;
	while (nb)
	{
		len++;
		nb = nb / base;
	}
	return (len);
}

char					*ft_itoa_base(unsigned long long int nb,\
int base, char add, t_param *p)
{
	char	*nb_base;
	int		len;
	int		i;

	len = ft_find_len(nb, base);
	if (nb == 0 && (p->p != 0 || (base == 8 && p->p == 0 && p->f[3] == 1)))
		len = 1;
	if (!(nb_base = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (nb == 0)
		nb_base[0] = '0';
	i = 1;
	while (nb)
	{
		if (nb % base > 9)
			nb_base[len - i] = nb % base + add - 10;
		else
			nb_base[len - i] = nb % base + '0';
		nb = nb / base;
		i++;
	}
	nb_base[len] = '\0';
	p->str_len = len;
	return (nb_base);
}
