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
	write(1, "Sort everything in alphabetical order, if keys"
	" -tfr are absent\n\n", 64);
	write(1, "Arguments:\n", 11);
	write(1, "  -a --all            do not ignore "
	"entries starting with .\n", 60);
	write(1, "  -R --recursive      list subdirectories recursively\n", 54);
	write(1, "  -l --long           use a long listing format\n", 48);
	write(1, "  -t --time           sort by modification "
	"time, newest first\n", 62);
	write(1, "  -r --reverse        do not ignore"
	" entries starting with .\n", 60);
	write(1, "  -f                  sort nothing\n", 35);
	write(1, "  -h --help           show this info and exit\n\n", 47);
	write(1, "Exit codes:\n", 12);
	write(1, "  0 - everything is great\n", 26);
	write(1, "  1 - minor errors\n", 19);
	write(1, "  2 - crashes\n", 14);
}

void	init_data(t_ls *data)
{
	data->flags.rec = 0;
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
}

void			show_link_and_name(const t_list *node)
{
	struct stat		st;
	char			*full_name;
	char			*link;
	size_t			r;

	ft_printf(GREEN "%s" WHITE, node->name);
	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
	{
		if (S_ISLNK(st.st_mode))
		{
			write(1, " -> ", 4);
			link = malloc(st.st_size + 1);
			r = readlink(full_name, link, st.st_size + 1);
			if ((unsigned)r > st.st_size)
				perror("ft_ls: symlink increased in size ");
			link[st.st_size] = '\0';
			write(1, link, st.st_size);
			free(link);
		}
	}
	else
		perror("ft_ls: stat");
	free(full_name);
	write(1, "\n", 1);
}

void			show_last_modification(const t_list *node)
{
	struct stat		st;
	char			*full_name;
	char			*str_time;
	short			i;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
	{
		i = 4;
		str_time = ctime(&st.st_mtime);
		while (i < 16)
		{
			write(1, &str_time[i], 1);
			i++;
		}
		write(1, " ", 1);
	}
	else
		perror("ft_ls: stat");
	free(full_name);
}

void			show_size(const t_list *node)
{
	struct stat		st;
	char			*full_name;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
		ft_printf("%10d ", st.st_size);
	else
		perror("ft_ls: stat");
	free(full_name);
}
