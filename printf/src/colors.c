/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/29 15:26:33 by smight            #+#    #+#             */
/*   Updated: 2019/05/29 15:26:35 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_colors(char *str)
{
	while (*str)
	{
		if (!ft_strncmp(str, "{RED}", 5))
			ft_memcpy(str, RED, 5);
		else if (!ft_strncmp(str, "{GRN}", 5))
			ft_memcpy(str, GRN, 5);
		else if (!ft_strncmp(str, "{YEL}", 5))
			ft_memcpy(str, YEL, 5);
		else if (!ft_strncmp(str, "{BLY}", 5))
			ft_memcpy(str, BLU, 5);
		else if (!ft_strncmp(str, "{MAG}", 5))
			ft_memcpy(str, MAG, 5);
		else if (!ft_strncmp(str, "{CYN}", 5))
			ft_memcpy(str, CYN, 5);
		else if (!ft_strncmp(str, "{WHT}", 5))
			ft_memcpy(str, WHT, 5);
		else if (!ft_strncmp(str, "{NRM}", 5))
			ft_memcpy(str, NRM, 5);
		str++;
	}
}
