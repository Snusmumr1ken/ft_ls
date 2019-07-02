/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_files_in_dir.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:32:39 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/06/27 09:32:41 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

static void			get_files_names_from_dir(t_ls *data, char *path)
{
	DIR				*dp;
	struct dirent	*ep;
	int				i;

	i = 0;
	if ((dp = opendir(path)) == NULL)
	{
		perror(path);
		return ;
	}
	while ((ep = readdir(dp)))
	{
		if ((data->flags.a || data->flags.f) ||
			(ft_strncmp(ep->d_name, ".", 1)))
			push(&data->file, ep->d_name, path);
	}
	closedir(dp);
}

static void			show_param_dirs(t_ls *data, char *path)
{
	DIR				*dp;
	struct dirent	*ep;
	char			newdir[512];

	ft_printf(BLUE "\n%s:\n" WHITE, path);
	get_files_names_from_dir(data, path);
	show_param_files(data);
	if (data->flags.rec)
	{
		dp = opendir(path);
		if (!dp)
		{
			perror(path);
			return ;
		}
		while ((ep = readdir(dp)))
		{
			if (ep->d_type == 4)
			{
				if (ft_strncmp(ep->d_name, ".", 1)) // if it simple dir add it to recursion
				{
					sprintf(newdir, "%s/%s", path, ep->d_name);
					show_param_dirs(data, newdir);
				}
				else if (data->flags.a || data->flags.f) // if we have flags a or f and it is hidden dir but not . or ..
				{
					if (!ft_strncmp(ep->d_name, ".", 1) && ft_strcmp(ep->d_name, ".") &&
						ft_strcmp(ep->d_name, "..")) // if it is hidden dir, but it is not . and ..
					{
						sprintf(newdir, "%s/%s", path, ep->d_name);
						show_param_dirs(data, newdir);
					}
				}
			}
		}
		closedir(dp);
	}
}

void inline			show_param_files(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
	else
		reverse_list(&data->file);
	if (data->flags.l == 0)
		show_list(&data->file);
	else
		show_long_list(&data->file);
	delete_list(&data->file);
}

void				show_all(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->dir, (data->flags.r == 0) ? 1 : 0);
	while (data->dir)
	{
		show_param_dirs(data, data->dir->name);
		data->dir = data->dir->next;
	}
	write(1, "\n", 1);
}
