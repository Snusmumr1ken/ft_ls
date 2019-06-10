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

typedef struct	s_flags
{
	bool	rec;
	bool	all;
	bool	lon;
	bool	rev;
	bool	time;
}		t_flags;

void		help(void);


#endif
