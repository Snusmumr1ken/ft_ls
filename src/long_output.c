/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   long_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/01 13:06:05 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/07/01 13:06:07 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

static void			show_link_and_name(const t_list *node)
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

static void			show_last_modification(const t_list *node)
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

static void			show_size(const t_list *node)
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

static void			show_user_group(const t_list *node)
{
	struct stat		st;
	struct passwd	*pw;
	struct group	*gr;
	char			*full_name;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
	{
		pw = getpwuid(st.st_uid);
		gr = getgrgid(st.st_gid);
		write(1, pw->pw_name, ft_strlen(pw->pw_name));
		write(1, "  ", 2);
		write(1, gr->gr_name, ft_strlen(gr->gr_name));
		write(1, " ", 1);
	}
	else
		perror("ft_ls: stat");
	free(full_name);
}

static void			show_hard_links(const t_list *node)
{
	struct stat		st;
	char			*full_name;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
		ft_printf("%3d ", st.st_nlink);
	else
		perror("ft_ls: stat");
	free(full_name);
}

static void			show_permissions(const t_list *node)
{
	struct stat		st;
	char			modeval[9];
	char			*full_name;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &st) == 0)
	{
		mode_t perm = st.st_mode;
		modeval[0] = (perm & S_IRUSR) ? 'r' : '-';
		modeval[1] = (perm & S_IWUSR) ? 'w' : '-';
		modeval[2] = (perm & S_IXUSR) ? 'x' : '-';
		modeval[3] = (perm & S_IRGRP) ? 'r' : '-';
		modeval[4] = (perm & S_IWGRP) ? 'w' : '-';
		modeval[5] = (perm & S_IXGRP) ? 'x' : '-';
		modeval[6] = (perm & S_IROTH) ? 'r' : '-';
		modeval[7] = (perm & S_IWOTH) ? 'w' : '-';
		modeval[8] = (perm & S_IXOTH) ? 'x' : '-';
		write(1, modeval, 9);
		write(1, "  ", 2);
	}
	else
		perror("ft_ls: stat");
	free(full_name);
}

static void			show_type(const t_list *node)
{
	struct stat		buf;
	char			*full_name;

	full_name = ft_strjoin(node->path, node->name);
	if (lstat(full_name, &buf) == 0)
	{
		if (S_ISLNK(buf.st_mode))
			write(1, "l", 1);
		else if (S_ISREG(buf.st_mode))
			write(1, "-", 1);
		else if (S_ISDIR(buf.st_mode))
			write(1, "d", 1);
		else if (S_ISCHR(buf.st_mode))
			write(1, "c", 1);
		else if (S_ISBLK(buf.st_mode))
			write(1, "b", 1);
		else if (S_ISFIFO(buf.st_mode))
			write(1, "p", 1);
		else if (S_ISSOCK(buf.st_mode))
			write(1, "s", 1);
	}
	else
		perror("ft_ls: stat");
	free(full_name);
}

void				show_long_list(t_list **head)
{
	t_list			*curr;

	curr = *head;
	//show total func
	while (curr)
	{
		show_type(curr);
		show_permissions(curr);
		show_hard_links(curr);
		show_user_group(curr);
		show_size(curr);
		show_last_modification(curr);
		show_link_and_name(curr);
		curr = curr->next;
	}
}
