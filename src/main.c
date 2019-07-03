/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 10:52:51 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/02/12 11:32:12 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

int		main(int argc, char **argv)
{
	t_ls			data;

	init_data(&data);
	(argc > 1) ? parse_arguments(argc, argv, &data) : 0;
	if (data.flags.h == 0)
	{
		(data.file == NULL && data.dir_len == 0) ?
			push(&data.dir, ".", ".") : 0;
		show_param_files(&data);
		show_all(&data);
	}
	else
		show_help();
	delete_list(&data.dir);
	delete_list(&data.file);
	return (0);
}
