#include "../includes/libls.h"

void	show_help(void)
{
	ft_printf("Usage: [KEY]... [FILE]...\n");
	ft_printf("Show info about files (in current directry by default).\n");
	ft_printf("Sort everything in alphabetical order, if keys -tr are abscent\n\n");
	ft_printf("Argumets:\n");
	ft_printf("	-a --all			do not ignore entries starting with .\n");
	ft_printf("	-R --recursive		list subdirectories recursively\n");
	ft_printf("	-l --long			use a long listing format\n");
	ft_printf("	-t --time			sort by modification time, newest first\n");
	ft_printf("	-r --reverse		do not ignore entries starting with .\n");
	ft_printf("	-h --help			show this info and exit\n\n");
	ft_printf("Exit codes:\n");
	ft_printf("  0 - everything is great\n");
	ft_printf("  1 - minor errors\n");
	ft_printf("  2 - crashes\n");
}

void	set_data_to_null(t_ls *data)
{
	data->flags.R = 0;
	data->flags.r = 0;
	data->flags.a = 0;
	data->flags.l = 0;
	data->flags.t = 0;
	data->flags.h = 0;
}

