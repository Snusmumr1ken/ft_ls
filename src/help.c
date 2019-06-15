#include "../includes/libls.h"

void	show_help(void)
{
	write(1, "Usage: [KEY]... [FILE]...\n", 26);
	write(1, "Show info about files (in current directry by default).\n", 56);
	write(1, "Sort everything in alphabetical order, if keys -tr are abscent\n\n", 64);
	write(1, "Argumets:\n", 10);
	write(1, "  -a --all            do not ignore entries starting with .\n", 60);
	write(1, "  -R --recursive      list subdirectories recursively\n", 54);
	write(1, "  -l --long           use a long listing format\n", 48);
	write(1, "  -t --time           sort by modification time, newest first\n", 62);
	write(1, "  -r --reverse        do not ignore entries starting with .\n", 60);
	write(1, "  -h --help           show this info and exit\n\n", 47);
	write(1, "Exit codes:\n", 12);
	write(1, "  0 - everything is great\n", 26);
	write(1, "  1 - minor errors\n", 19);
	write(1, "  2 - crashes\n", 14);
}

void	init_data(t_ls *data)
{
	data->flags.R = 0;
	data->flags.r = 0;
	data->flags.a = 0;
	data->flags.l = 0;
	data->flags.t = 0;
	data->flags.h = 0;
	data->dir = (t_list*)malloc(sizeof(t_list));
	data->dir->name = NULL;
	data->dir->next = NULL;
	data->dir->list_inside = NULL;
}

void	clear_all(t_ls *data)
{
	/*
	 * нужно пройтись по всем листам
	 * и удалить все элементы
	 */
}
