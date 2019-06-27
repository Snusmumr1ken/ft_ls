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


#include <stdio.h>

# include "../my_libft/includes/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>


typedef struct			s_list
{
	char				*name;
	struct s_list		*list_inside;
	struct s_list		*next;
}						t_list;

/*
 ** struct s_flags contains
 ** bool flags
*/

typedef struct			s_flags
{
	bool				R;
	bool				a;
	bool				l;
	bool				r;
	bool				t;
	bool				h;
	bool				f;
}						t_flags;

/*
 ** struct s_ls contains all
 ** nessesary data for ls
*/

typedef struct			s_ls
{
	t_flags				flags;
	t_list				*dir; //директории указанные как параметры, если параметров нет записывается текущая директория
	t_list				*file; //файлы указанные как параметры
}						t_ls;


void					show_all(t_ls *data);
void					merge_sort(t_list **headRef);
void					show_help(void);
void					parse_arguments(int argc, char **argv, t_ls *data);
void					init_data(t_ls *data);

void					clear_all(t_list **head);
void					create_list_inside_list(t_list **head, char *name, char *new_name);
void					show_list(t_list **head);
void					push(t_list **head, char *name);


#endif
