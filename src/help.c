/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 08:44:10 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/06/27 08:47:01 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

void	show_help(void)
{
	write(1, "Usage: ft_ls [KEY]... [FILE]...\n\n", 33);
	write(1, "Show info about files (in current directory by default).\n", 57);
	write(1, "Sort everything in alphabetical order, if keys -tfr are absent\n\n", 64);
	write(1, "Arguments:\n", 11);
	write(1, "  -a --all            do not ignore entries starting with .\n", 60);
	write(1, "  -R --recursive      list subdirectories recursively\n", 54);
	write(1, "  -l --long           use a long listing format\n", 48);
	write(1, "  -t --time           sort by modification time, newest first\n", 62);
	write(1, "  -r --reverse        do not ignore entries starting with .\n", 60);
	write(1, "  -f                  sort nothing\n", 35);
	write(1, "  -h --help           show this info and exit\n\n", 47);
	write(1, "Exit codes:\n", 12);
	write(1, "  0 - everything is great\n", 26);
	write(1, "  1 - minor errors\n", 19);
	write(1, "  2 - crashes\n\n\n", 16);
}

void	init_data(t_ls *data)
{
	data->flags.R = 0;
	data->flags.r = 0;
	data->flags.a = 0;
	data->flags.l = 0;
	data->flags.t = 0;
	data->flags.h = 0;
	data->flags.f = 0;
	data->dir = NULL;
	data->file = NULL;
	data->no_params = 1;
	data->dir_len = 0;
	data->file_len = 0;
}
