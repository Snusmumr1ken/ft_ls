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
	DIR		*dir;
	struct dirent	*sd;


	dir = opendir(".");
	if (dir == NULL)
	{
		perror("opendir");
		exit(1);
	}


	/*while ((sd = readdir(dir)) != NULL)
	{
		if (sd->d_name[0] != '.')
			ft_printf("%c %s\n", sd->d_type, sd->d_name);
	}*/


	help();

	closedir(dir);
	return (0);
}
