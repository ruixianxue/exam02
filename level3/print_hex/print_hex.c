#include <unistd.h>
#include <stdio.h>

void    put_hex(int n)
{
    char *base = "0123456789abcdef";

    if (n >= 16)
    {
        put_hex(n / 16);
        put_hex(n % 16);
    }
    else
        write(1, &base[n], 1);
}

int ft_atoi(char *str)
{
    int i = 0;
    int sign = 1;
    int res = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9')
    {
        res = res * 10 + str[i] - '0';
        i++;
    }
    return (res * sign);
}

int main(int ac, char **av)
{
    if (ac == 2)
    {
        int n = ft_atoi(av[1]);
        if (n >= 0)
            put_hex(n);
    }
    write(1, "\n", 1);
}
