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
static void			show_param_files(t_ls *data);
static void			show_param_dirs(t_ls *data);

void				show_all(t_ls *data)
{
	t_list *curr;

	show_param_files(data);
	show_param_dirs(data);

	/* если параметров не было просто выводим содержимое . */
	if (data->no_params == 1)
	{
		push(&data->dir, ".");
		get_files_names_from_dir(data, data->dir->name);
		merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
		show_list(&data->file);
	}
}

static void			show_param_dirs(t_ls *data)
{
	t_list *curr;

	if (data->flags.f == 0)
		merge_sort(&data->dir, (data->flags.r == 0) ? 1 : 0);
	curr = data->dir;
	while (curr)
	{
		get_files_names_from_dir(data, curr->name);
		ft_printf("%s :\n", curr->name);
		if (data->flags.f == 0)
			merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
		show_list(&data->file);
		delete_list(&data->file);
		curr = curr->next;
		(curr != NULL) ? write(1, "\n", 1) : 0;
	}
}

static void			show_param_files(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->file, (data->flags.r == 0) ? 1 : 0);
	show_list(&data->file);
	(data->file != NULL && data->dir != NULL) ? write(1, "\n", 1) : 0;
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
