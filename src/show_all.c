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

static void			get_files_names_from_dir(t_ls *data, char *path);
static void			show_param_dirs(t_ls *data, char *path);
void				show_param_files(t_ls *data);

void				show_all(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->dir, (data->flags.r == 0) ? 1 : 0);

	while (data->dir)
	{
		show_param_dirs(data, data->dir->name);
		data->dir = data->dir->next;
	}
}

static void		show_param_dirs(t_ls *data, char *path)
{
	DIR				*dp;
	struct dirent	*ep;
	char			newdir[512];

	write(1, "\n", 1);
	ft_printf(BLUE "%s:\n" WHITE, path);
	get_files_names_from_dir(data, path);
	if (data->flags.f == 0)
		merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
	show_param_files(data);
	if (data->flags.R)
	{
		dp = opendir(path);
		while ((ep = readdir(dp)))
		{
			if (strncmp(ep->d_name, ".", 1))
			{
				if (ep->d_type == 4)
				{
					sprintf(newdir, "%s/%s", path, ep->d_name);
					show_param_dirs(data, newdir);
				}
			}
		}
		closedir(dp);
	}
}

void			show_param_files(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
	show_list(&data->file);
	delete_list(&data->file);
}


static void			get_files_names_from_dir(t_ls *data, char *path)
{
	DIR				*dp;
	struct dirent	*ep;

	if ((dp = opendir(path)) == NULL)
	{
		perror(path);
		return ;
	}
	while ((ep = readdir(dp)))
	{
		if ((data->flags.a || data->flags.f) ||
			(strncmp(ep->d_name, ".", 1)))
			push(&data->file, ep->d_name);
	}
	closedir(dp);
}
