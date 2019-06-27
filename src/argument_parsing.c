/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_parsing.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anyvchyk <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 08:52:19 by anyvchyk          #+#    #+#             */
/*   Updated: 2019/06/27 08:52:21 by anyvchyk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libls.h"

static void		parse_long_arg(char *arg, t_ls *data);
static void		parse_short_arg(char *arg, t_ls *data);
static void		parse_dir_or_file_name(char *arg, t_ls *data);
static void		show_error_param(char *arg, t_ls *data);

void			parse_arguments(int argc, char **argv, t_ls *data)
{
	short	i;

	i = 0;
	while (++i < argc)
	{
		if (argv[i][0] != '-')
			parse_dir_or_file_name(argv[i], data);
		else if (argv[i][0] == '-' && argv[i][1] == '-')
			parse_long_arg(argv[i], data);
		else if (argv[i][0] == '-' && argv[i][1] != '-')
			parse_short_arg(argv[i], data);
	}
}

static void		parse_dir_or_file_name(char *arg, t_ls *data)
{
	DIR			*dir;

	if ((dir = opendir(arg)) == NULL && errno == 20)
		push(&data->file, arg);
	else if (errno != 0 || ((closedir(dir)) != 0))
	{
		perror("ft_ls: unable to get access");
		delete_list(&data->dir);
		delete_list(&data->file);
		exit(2);
	}
	else
		push(&data->dir, arg);
}

static void		parse_long_arg(char *arg, t_ls *data)
{
	if (!ft_strcmp(arg, "--help"))
		data->flags.h = 1;
	else if (!ft_strcmp(arg, "--reverse"))
		data->flags.r = 1;
	else if (!ft_strcmp(arg, "--time"))
		data->flags.t = 1;
	else if (!ft_strcmp(arg, "--long"))
		data->flags.l = 1;
	else if (!ft_strcmp(arg, "--recursive"))
		data->flags.R = 1;
	else if (!ft_strcmp(arg, "--all"))
		data->flags.a = 1;
	else
		show_error_param(arg, data);
}

static void		parse_short_arg(char *arg, t_ls *data)
{
	short	i;

	i = 0;
	while (++i < ft_strlen(arg))
	{
		if (arg[i] == 'r')
			data->flags.r = 1;
		else if (arg[i] == 't')
			data->flags.t = 1;
		else if (arg[i] == 'l')
			data->flags.l = 1;
		else if (arg[i] == 'R')
			data->flags.R = 1;
		else if (arg[i] == 'a')
			data->flags.a = 1;
		else if (arg[i] == 'f')
			data->flags.f = 1;
		else
			show_error_param(&arg[i], data);
	}
}

static void		show_error_param(char *arg, t_ls *data)
{
	write(2, "ft_ls: unknown parametr <<", 26);
	write(2, arg, ft_strlen(arg));
	write(2, ">>\nYou can use <<ft_ls --help>> to get additional info\n", 55);
	delete_list(&data->dir);
	delete_list(&data->file);
	exit(2);
}
