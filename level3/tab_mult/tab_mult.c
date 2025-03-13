#include <unistd.h>

void    putnbr(int n)
{
    if (n > 9)
        putnbr(n / 10);
    char c = n % 10 + '0';
    write(1, &c, 1);
}

void    putstr(char *str)
{
    int i = 0;

    while (str[i])
    {
        write(1, &str[i], 1);
        i++;
    }
}

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res);
}

int main(int ac, char **av)
{
    int n;

    if (ac == 2)
    {
        n = ft_atoi(av[1]);
        for(int i = 1; i <= 9; i++)
        {
            putnbr(i);
            putstr(" x ");
            putnbr(n);
            putstr(" = ");
            putnbr(i * n);
            putstr("\n");
        }
    }
    else
        putstr("\n");
}
