#include <unistd.h>

int main(int ac, char **av)
{
    char    asc[256] = {0};

    int i = 0;
    if (ac == 3)
    {
        while (av[1][i])
        {
            if (asc[(int)av[1][i]] == 0)
                write(1, &av[1][i], 1);
            asc[(int)av[1][i]] = 1; 
            i++;
        }
        i = 0;
        while (av[2][i])
        {
            if (asc[(int)av[2][i]] == 0)
                write(1, &av[2][i], 1);
            asc[(int)av[2][i]] = 1;
            i++;
        }
    }
    write(1, "\n", 1);
}
