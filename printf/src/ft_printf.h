/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsumner <rsumner@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/31 11:16:20 by rsumner           #+#    #+#             */
/*   Updated: 2019/06/03 15:55:00 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# define BUFF_SIZE_P 10000
# include "../../libft/libft.h"

typedef struct				s_param
{
	va_list					ar;
	int						f[6];
	int						w;
	int						p;
	int						l[5];
	int						t;
	int						str_len;
	char					*str;
	char					sign;
}							t_param;

typedef struct				s_result
{
	char					*buff;
	int						len;
	int						sum;
	int						fd;
}							t_result;

int							ft_printf(char *arg, ...);
int							ft_fprintf(int fd, char *arg, ...);
int							ft_add_data(char *arg, int i, t_param *param);
int							is_flag(char c);
int							is_length(char c);
int							is_type(char c);
int							ft_treat_data(t_param *param, t_result *result);
int							ft_c(t_param *param);
int							ft_s(t_param *param);
int							ft_p(t_param *param);
int							ft_d(t_param *param);
int							ft_i(t_param *param);
int							ft_o(t_param *param);
int							ft_u(t_param *param);
int							ft_x(t_param *param);
int							ft_xbig(t_param *param);
int							ft_b(t_param *param);
int							ft_sbig(t_param *param);
int							ft_cbig(t_param *param);
int							ft_add(t_param *p);
unsigned long long int		get_unsig_nb(t_param *param);
long long int				get_sig_nb(t_param *param);
int							ft_base(t_param *p, int base, char add);
char						*ft_itoa_base(unsigned long long int nb, int base,\
		char add, t_param *param);
int							ft_fill(char *str, char c, int len);
int							ft_choose(int a, int b);
int							handle_base(t_param *p);
int							handle_di(t_param *p);
int							handle_sc(t_param *p);

# define F_PLUS 0
# define F_MINUS 1
# define F_SPACE 2
# define F_SHARP 3
# define F_ZERO 4
# define F_SLASH 5

# define L_L 0
# define L_H 1
# define L_BIGL 2

# define MAX_LEN 5000
# define MAX_INDEX 4999

# define T_F 1
# define T_BIGF 2

# define NRM  "\x1B[00m"
# define RED  "\x1B[31m"
# define GRN  "\x1B[32m"
# define YEL  "\x1B[33m"
# define BLU  "\x1B[34m"
# define MAG  "\x1B[35m"
# define CYN  "\x1B[36m"
# define WHT  "\x1B[37m"

typedef struct				s_number
{
	char					num[MAX_LEN + 1];
	size_t					cap;
}							t_number;

union						u_double
{
	long double				ld;
	struct
	{
		unsigned long int	mant : 64;
		unsigned int		expon : 15;
		unsigned int		sign : 1;
	}						s_parts;
};

int							ft_f(t_param *p);
void						ft_magic_sum(t_number *n1, t_number n2);
void						ft_magic_mult_n(t_number *r, t_number n1,\
		char n2, size_t shift);
t_number					ft_new_number(char n);
t_number					ft_magic_mult(t_number n1, t_number n2);
t_number					ft_magic_power(size_t pow, t_number n);
char						*ft_upgrade(t_param *p, char *s);
char						*ft_strfjoin(char const *s1, char const *s2);
int							ft_specific_values(union u_double d, t_param *p);
void						ft_colors(char *str);
int							ft_sign(t_param *p);
int							ft_width(t_param *p);

/**
 * buffer!
 */
t_result                    result;

void                        print_buffer(int fd);

#endif
