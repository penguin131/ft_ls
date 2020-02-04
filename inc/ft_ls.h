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

#include "ft_ls.h"
#include "../libft/libft.h"
#include "../printf/src/ft_printf.h"

#include <sys/stat.h>
#include <sys/xattr.h>
#include <sys/ioctl.h>

#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>

#define R_FLAG 0b10000000
#define L_FLAG 0b01000000
#define A_FLAG 0b00100000
#define T_FLAG 0b00010000
#define REC_FL 0b00001000
#define U_FLAG 0b00000100

#define MAX_PATH_LEN 1024
#define NAMES_CNT 5000
#define FLAG_TYPES "alRrtu"

typedef struct		s_file
{
	char 			*name;
	char			*path_name;
	char 			is_error;
	int				name_len;
	int 			length;
	int 			capacity;
	int				size;
	char			*username;
	char			*year;
	unsigned long	st_mode;
	unsigned long	n_link;
	unsigned long	total_n_link;
	short			max_n_link_len;
	short			max_size_len;
	time_t			time;
	struct s_file	*files;
}					t_file;

typedef struct		s_info
{
    char			**names_pool;
    t_list			*reserved_names_pool;
    int 			current_index;
    int				pool_len;
	int 			start;//after flags
	t_file			mock_folder;
	unsigned char	flags;
	char			is_not_first;
}					t_info;

void    print_invalid_folders(t_info *info);
void	malloc_error(t_info *info);
void	add_new_file(t_info *info, t_file *file, t_file *new_file);
void	print_files(t_info *info, t_file *file);
void	read_nested_folders(t_info *info, t_file *root);
void    read_folder(t_info *info, t_file *input_file);
void	free_data(t_info *info, t_file *file);
void	file_sorting(t_info *info, t_file *file);
void	read_folder_args(t_info *info, int argc, char **argv);
void	read_flags(t_info *info, int argc, char **argv);
int		is_hidden_root(t_info *info, const char *name);
void	add_new_filename(t_info *info, const char *path, const char *name, t_file *file);
void print_l(t_file *file);
void	free_list_without_func(t_list **list);

#endif
