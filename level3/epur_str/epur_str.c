#include <unistd.h>

int main(int ac, char **av)
{
    int space = 0;
    int i = 0;

    if (ac == 2)
    {
        while (av[1][i] == ' ' || av[1][i] == '\t')
            i++;
        while (av[1][i])
        {
            if (av[1][i] != ' ' && av[1][i] != '\t')
            {
                if (space)
                write(1, " ", 1);
                space = 0;
                write(1, &av[1][i], 1);
            }
            if (av[1][i] == ' ' || av[1][i] == '\t')
                space = 1;
            i++;
        }
    }
    write(1, "\n", 1);
}
