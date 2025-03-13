#include <unistd.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putnbr(int nbr)
{
    if (nbr >= 10)
        ft_putnbr(nbr / 10);
    ft_putchar(nbr % 10 + '0');
}

int is_prime(int nbr)
{
    if (nbr < 2)
        return (0);
    int i = 2;
    while (i * i <= nbr)
    {
        if (nbr % i == 0)
            return (0);
        i++;
    }
    return (1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int res = 0;

    if (str[i] == '-')
        return (-1);
    while (str[i])
    {
        res = res * 10 + (str[i] - '0');
        i++;
    }
    return (res);
}

int main(int ac, char **av)
{
    int i = 0;
    int sum = 0;
    if (ac == 2 && ft_atoi(av[1]) > 0)
    {
        int n = ft_atoi(av[1]);
        while (n > 1)
        {
            if (is_prime(n))
                sum += n;
            n--;
        }
    }
    ft_putnbr(sum);
    ft_putchar('\n');
    return (0);
}

