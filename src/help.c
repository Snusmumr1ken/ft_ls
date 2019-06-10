#include "../includes/libls.h"

void	help(void)
{
	ft_printf("Usage: [KEY]...\n");
	ft_printf("Argumets:\n");
	ft_printf("	-a --all		do not ignore entries starting with .\n");
	ft_printf("	-R --recursive		list subdirectories recursively\n");
	ft_printf("	-l --long		use a long listing format\n");
	ft_printf("	-t --time		sort by modification time, newest first\n");
	ft_printf("	-r --reverse		do not ignore entries starting with .\n");
	ft_printf("	-h --help		show this info and exit\n\n");
	ft_printf("Exit codes:\n");
	ft_printf("  0 - everything is great\n");
	ft_printf("  1 - minor errors\n");
	ft_printf("  2 - crashes\n");
}
