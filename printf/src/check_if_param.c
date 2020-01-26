/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_if_param.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/30 18:16:47 by rsumner           #+#    #+#             */
/*   Updated: 2019/05/31 12:05:24 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_flag(char c)
{
	if (c == '+')
		return (0);
	if (c == '-')
		return (1);
	if (c == ' ')
		return (2);
	if (c == '#')
		return (3);
	if (c == '0')
		return (4);
	if (c == '\'')
		return (5);
	return (-1);
}

int	is_length(char c)
{
	if (c == 'l')
		return (0);
	if (c == 'h')
		return (1);
	if (c == 'L')
		return (2);
	if (c == 'j')
		return (3);
	if (c == 'z')
		return (4);
	return (-1);
}

int	is_type(char c)
{
	char	*type;
	int		i;

	type = "%fFdiouxXbpscSC";
	i = 0;
	while (type[i])
	{
		if (c == type[i])
			return (i);
		i++;
	}
	return (-1);
}
