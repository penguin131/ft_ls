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

#define MAX_NAME_LEN 255
#define PATH_NAME_LEN 4096

typedef struct		s_data
{
	struct s_file	*files;
	int 			length;
	int 			capacity;
}					t_data;

typedef struct		s_file
{
	char 			name[MAX_NAME_LEN];
	char			path[PATH_NAME_LEN];
	char			path_name[PATH_NAME_LEN + MAX_NAME_LEN];
	char			is_folder;
	struct s_data	file_data;
}					t_file;

typedef struct		s_info
{
	char			flags;
	char 			is_many_folders;
	t_file			root_file;
}					t_info;

void    invalid_folder_error(t_info *info, char *folder_name);
void	malloc_error(t_info *info);
void	add_new_file(t_info *info, t_file *file, t_file new_file);
void	print_files(t_info *info, t_file *file);
void	read_nested_folders(t_info *info, t_file *root);
void    read_folder(t_info *info, t_file *input_file);
void	free_data(t_file *file);
void	file_sorting(t_file *file);
void	read_folder_args(t_info *info, int argc, char **argv);

#endif
