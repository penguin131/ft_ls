/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smight <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/26 11:10:57 by smight            #+#    #+#             */
/*   Updated: 2019/07/26 11:10:59 by smight           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
#define FT_LS_H

#include "../libft/libft.h"
#include <dirent.h>
#include <sys/stat.h>

#define R_FLAG 0b10000000
#define L_FLAG 0b01000000
#define A_FLAG 0b00100000
#define T_FLAG 0b00010000
#define REC_FL 0b00001000

typedef struct		s_file
{
    char 			*name;
    struct s_data	*file;
}					t_file;

typedef struct		s_data
{
	char 			**names_pool;
	int 			length;
	int 			capacity;
	char			flags;
}					t_data;

void    invalid_folder_error(t_data *data, char *folder_name);
void	malloc_error(t_data *data);
void	add_new_name_to_pool(t_data *data, char *file);
void	print_files(t_data *data);
void	read_nested_folders(t_data *data);
void    read_folder(t_data *data, char *folder_name);
void	free_names_pool(t_data *data);

#endif
