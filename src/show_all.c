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

static void			the_great_cycle_for_recursion(t_ls *data, DIR *dp,
		char *newdir, char *path)
{
	struct dirent	*ep;

	while ((ep = readdir(dp)))
	{
		if (ep->d_type == 4)
		{
			if (ft_strncmp(ep->d_name, ".", 1))
			{
				sprintf(newdir, "%s/%s", path, ep->d_name);
				show_param_dirs(data, newdir);
			}
			else if (data->flags.a || data->flags.f)
			{
				if (!ft_strncmp(ep->d_name, ".", 1) &&
					ft_strcmp(ep->d_name, ".") &&
					ft_strcmp(ep->d_name, ".."))
				{
					sprintf(newdir, "%s/%s", path, ep->d_name);
					show_param_dirs(data, newdir);
				}
			}
		}
	}
	closedir(dp);
}

inline void			show_param_files(t_ls *data)
{
	if (data->flags.f == 0)
	{
		merge_sort(&data->file, (data->flags.t) ? 2 : 1);
		(data->flags.r) ? reverse_list(&data->file) : 0;
	}
	else
		reverse_list(&data->file);
	if (data->flags.l == 0)
		show_list(&data->file);
	else
		show_long_list(&data->file);
	delete_list(&data->file);
}

static void			cycle(t_ls *data, t_list **head)
{
	t_list *tmp;

	tmp = *head;
	while (tmp)
	{
		show_param_dirs(data, tmp->name);
		tmp = tmp->next;
	}
}

void				show_all(t_ls *data)
{
	if (data->flags.f == 0)
	{
		merge_sort(&data->dir, (data->flags.t) ? 2 : 1);
		(data->flags.r) ? reverse_list(&data->dir) : 0;
	}
	else
		reverse_list(&data->dir);
	cycle(data, &data->dir);
	write(1, "\n", 1);
}
