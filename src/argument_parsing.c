#include "../includes/libls.h"

static void		parse_long_arg(char *arg, t_ls *data);
static void		parse_short_arg(char *arg, t_ls *data);
static void		parse_dir_or_file_name(char *arg, t_ls *data);

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

// 1 == file, 0 == dir
static bool 	file_or_dir(char *arg)
{
	DIR			*dir;

	if ((dir = opendir(arg)) == NULL && errno == 20)
		return (1);
	if (errno != 0)
	{
		perror("ls: unable to get access");
		exit(2);
	}
	if ((closedir(dir)) != 0)
	{
		perror("ls: unable to close directory");
		exit(2);
	}
	return (0);
}

static void		parse_dir_or_file_name(char *arg, t_ls *data)
{
	if ((file_or_dir(arg) == 0)
	{
		//добавляем в лист дирекорию
	}
	else
		//добавляем в лист файл
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
	{
		write(2, "ls: unknown parametr <<", 23);
		write(2, arg, ft_strlen(arg));
		write(2, ">>\nYou can use <<ls --help>> to get additional info\n", 52);
		exit(2);
	}
}

static void		parse_short_arg(char *arg, t_ls *data)
{
	short	i;
	short	arg_len;
	
	arg_len = (short)ft_strlen(arg);
	i = 0;
	while (++i < arg_len)
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
		else
		{
			write(2, "ls: unknown parametr <<", 23);
			write(2, &arg[i], 1);
			write(2, ">>\nYou can use <<ls --help>> to get additional info\n", 52);
			exit(2);
		}
	}
}
