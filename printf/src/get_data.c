/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_data.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 10:36:01 by rsumner           #+#    #+#             */
/*   Updated: 2019/05/31 10:41:04 by rsumner          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_error(char *str)
{
	ft_strdel(&str);
	return (-1);
}

void	ft_blank_struc(t_param *param)
{
	param->f[0] = 0;
	param->f[1] = 0;
	param->f[2] = 0;
	param->f[3] = 0;
	param->f[4] = 0;
	param->f[5] = 0;
	param->w = -1;
	param->p = -1;
	param->l[0] = 0;
	param->l[1] = 0;
	param->l[2] = 0;
	param->l[3] = 0;
	param->l[4] = 0;
	param->t = -1;
	param->str = NULL;
	param->str_len = 0;
	param->sign = '+';
}

int		ft_printf(char *arg, ...)
{
	t_param		param;
	int			i;

	va_start(param.ar, arg);
	i = 0;
	result.fd = 1;
	while (arg[i])
	{
		ft_blank_struc(&param);
		if ((i = ft_add_data(arg, i, &param)) == -1)
			return (ft_error(param.str));
		param.w == -2 ? param.w = va_arg(param.ar, int) : 0;
		param.p == -2 ? param.p = va_arg(param.ar, int) : 0;
		if (ft_treat_data(&param, &result) < 0)
			return (ft_error(param.str));
	}
	//print_buffer(-1);
	va_end(param.ar);
	return (result.sum + result.len);
}

int		ft_fprintf(int fd, char *arg, ...)
{
	t_param		param;
	int			i;

	va_start(param.ar, arg);
	i = 0;
	result.fd = fd;
	while (arg[i])
	{
		ft_blank_struc(&param);
		if ((i = ft_add_data(arg, i, &param)) == -1)
			return (ft_error(param.str));
		param.w == -2 ? param.w = va_arg(param.ar, int) : 0;
		param.p == -2 ? param.p = va_arg(param.ar, int) : 0;
		if (ft_treat_data(&param, &result) < 0)
			return (ft_error(param.str));
	}
    //print_buffer(result.fd);
	va_end(param.ar);
	return (result.sum + result.len);
}

void    print_buffer(int fd)
{
    write(fd == -1 ? 1 : result.fd, result.buff, result.len);
}
