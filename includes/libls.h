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
# include <dirent.h>
# include <errno.h>
# include <stdbool.h>



typedef struct			s_node
{
	char				*name;
	struct s_file_node	*next;
}						t_node;

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
}						t_flags;

/*
 ** struct s_ls contains all
 ** nessesary data for ls
*/

typedef struct			s_ls
{
	t_flags				flags;
}						t_ls;


void					show_help(void);
void					parse_arguments(int argc, char **argv, t_ls *data);
void					set_data_to_null(t_ls *data);

#endif
