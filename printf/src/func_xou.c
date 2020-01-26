/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   func_xou.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:24:19 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 15:47:20 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_base(t_param *p, int base, char add)
{
	unsigned long long int nb;

	nb = get_unsig_nb(p);
	if (!(p->str = ft_itoa_base(nb, base, add, p)))
		return (-1);
	if (nb == 0 && (p->t != 10))
		p->f[3] = 0;
	if (ft_add(p) == -1)
		return (-1);
	return (0);
}

int	ft_x(t_param *param)
{
	if (ft_base(param, 16, 'a') == -1)
		return (-1);
	return (0);
}

int	ft_xbig(t_param *param)
{
	if (ft_base(param, 16, 'A') == -1)
		return (-1);
	return (0);
}

int	ft_o(t_param *param)
{
	if (ft_base(param, 8, 'A') == -1)
		return (-1);
	return (0);
}

int	ft_u(t_param *param)
{
	if (ft_base(param, 10, 'A') == -1)
		return (-1);
	return (0);
}
