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

void				show_all(t_ls *data)
{
	if (data->flags.f == 0)
		merge_sort(&data->file);
	show_list(&data->file);
}
