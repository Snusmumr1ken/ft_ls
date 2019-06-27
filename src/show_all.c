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

void				show_all(t_ls *data)
{
	if (data->dir->name[0] == '.')
		get_files_names_from_dir(data, data->dir->name);
	if (data->flags.f == 0)
		merge_sort(&data->file);
	show_list(&data->file);
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
