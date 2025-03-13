#include <unistd.h>
#include <stdlib.h>

void    rev_wstr(char *str, int first)
{
    int i = 0;
    int start;

    if (str[i])
    {
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        start = i;
        if (!str[i])
            return ;
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        rev_wstr(&str[i], 0);
        write(1, &str[start], i - start);
        if (!first)
            write(1, " ", 1);
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1], 1);
    write(1, "\n", 1);
}