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
#include "ft_ls.h"

#define R_FLAG 0b10000000
#define L_FLAG 0b01000000
#define A_FLAG 0b00100000
#define T_FLAG 0b00010000
#define REC_FL 0b00001000

/**
 * как соответствующие им константы в #include <sys/syslimits.h> - MAXNAMLEN и PATH_MAX
 */
#define MAX_NAME_LEN 255
#define MAX_PATH_LEN 1024
#define NAMES_CNT 5000

#define FLAG_TYPES "alRrt"

typedef struct		s_file
{
	char 			*name;
	char			*path_name;
	char			is_folder;
	char 			is_error;
	int 			length;
	int 			capacity;
	t_list			*files;
}					t_file;

typedef struct		s_info
{
    char            names_pool[NAMES_CNT][MAX_PATH_LEN];
    t_list			*reserved_names_pool;
    int 			current_index;
    int				pool_len;
	int 			start;//after flags
	t_file			mock_folder;
}					t_info;

unsigned char		flags;

void    print_invalid_folders(t_info *info);
void	malloc_error(t_info *info);
void	add_new_file(t_info *info, t_file *file, t_file *new_file);
void	print_files(t_info *info, t_file *file);
void	read_nested_folders(t_info *info, t_file *root);
void    read_folder(t_info *info, t_file *input_file);
void	free_data(t_info *info, t_file *file);
void	file_sorting(t_file *file);
void	read_folder_args(t_info *info, int argc, char **argv);
void	read_flags(t_info *info, int argc, char **argv);
int     is_hidden_root(const char *name);
void	add_new_filename(t_info *info, const char *path, const char *name, t_file *file);

#endif
