/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:53:54 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/02/12 11:19:47 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBLS_H
# define LIBLS_H

# define GREEN   "\x1b[32m"
# define BLUE    "\x1b[34m"
# define WHITE   "\x1b[37m"

#include <stdio.h>

# include "../libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>
# include <time.h>
# include <pwd.h>
# include <grp.h>
# include <uuid/uuid.h>

typedef struct			s_list
{
	char				*name;
	char 				*path;
	struct s_list		*next;
}						t_list;

typedef struct			s_flags
{
	bool				rec;
	bool				a;
	bool				l;
	bool				r;
	bool				t;
	bool				h;
	bool				f;
}						t_flags;

typedef struct			s_ls
{
	t_flags				flags;
	t_list				*dir;
	t_list				*file;
	unsigned short		dir_len;
	bool				no_params;
}						t_ls;

void					show_param_files(t_ls *data);
void					show_all(t_ls *data);
void					merge_sort(t_list **head_ref, const int how_to_sort);
void					reverse_list(t_list **head_ref);
void					show_help(void);
void					parse_arguments(int argc, char **argv, t_ls *data);
void					init_data(t_ls *data);
void					delete_list(t_list **head);
void					show_list(t_list **head);
void					show_long_list(t_list **head);
void					push(t_list **head, char *name, char *path);
void					show_link_and_name(const t_list *node);
void					show_last_modification(const t_list *node);
void					show_size(const t_list *node);

#endif
