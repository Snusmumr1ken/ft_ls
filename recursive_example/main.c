#include <stdio.h>
#include <dirent.h>
#include <string.h>

# define GREEN   "\x1b[32m"
# define BLUE    "\x1b[34m"
# define WHITE   "\x1b[37m"

void		Usage()
{
    fprintf(stderr, "\nUsage: exec [OPTION]... [DIR]...\n");
    fprintf(stderr, "List DIR's (directory) contents\n");
    fprintf(stderr, "\nOptions\n-R\tlist subdirectories recursively\n");
    return ;
}

void		rec_dir(char *path, int flag)
{
    DIR				*dp = opendir(path);
	struct dirent	*ep;
	char			newdir[512];

    if(!dp)
    {
        perror(path);
        return;
    }

    printf(BLUE "%s :\n" WHITE, path);

    /* идём в цикле по директории */
    while ((ep = readdir(dp)))
    {
    	/* если это не скрытый файл - выводим его имя */
		if (strncmp(ep->d_name, ".", 1))
			printf(GREEN "\t%s\n" WHITE, ep->d_name);
	}
    closedir(dp);

    /* если директория - открываем ёё рекурсивно */
    dp = opendir(path);
    while ((ep = readdir(dp)))
    {
		if (strncmp(ep->d_name, ".", 1))
		{
			if (flag && ep->d_type == 4)
			{
				sprintf(newdir, "%s/%s", path, ep->d_name);
				rec_dir(newdir, 1);
			}
		}
	}
    closedir(dp);
}

int main(int argc, char **argv)
{
    switch(argc)
    {
    case 2: // если 2 параметра
        if (!(strcmp(argv[1], "-R"))) //и это флаг -R
        	Usage(); //показываем как пользоваться программой
        else // если два параметра и это не флаг -R
        	rec_dir(argv[1], 0); // вызываем НЕрекурсивную функцию чтения со вторым параметром
        break;

    case 3: // если 3 параметра
        if (!(strcmp(argv[1], "-R"))) // второй это флаг -R
        	rec_dir(argv[2], 1); // вызываем рекурсивную функцию чтения с третьим параметром
        else
        	Usage();
        break;

    default:
    	Usage();
    }
    return 0;
}
