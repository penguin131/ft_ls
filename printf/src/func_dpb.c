/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_dpb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:23:21 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 11:02:59 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_d(t_param *p)
{
	long long int nb;

	nb = get_sig_nb(p);
	if (nb < 0)
	{
		nb = -nb;
		p->sign = '-';
		p->f[0] = 1;
	}
	if (!(p->str = ft_itoa_base(nb, 10, '0', p)))
		return (-1);
	if (ft_add(p) == -1)
		return (-1);
	return (0);
}

int	ft_p(t_param *param)
{
	param->f[3] = 1;
	param->l[0] = 2;
	if (ft_base(param, 16, 'a') == -1)
		return (-1);
	return (0);
}

int	ft_b(t_param *param)
{
	if (ft_base(param, 2, 'A') == -1)
		return (-1);
	return (0);
}
