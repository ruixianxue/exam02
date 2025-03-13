
#include <stdlib.h>

int nbr_len(long nbr)
{
    int len = 0;

    if (nbr == 0)
        return (1);
    if (nbr < 0)
    {
        len++;
        nbr = -nbr;
    }
    while (nbr > 0)
    {
        nbr /= 10;
        len++;
    }
    return (len);
}

void    fill_string(char *str, long nbr, int len)
{
    str[len] = '\0';
    if (nbr == 0)
        str[0] = '0';
    else
    {
        if (nbr < 0)
        {
            str[0] = '-';
            nbr = -nbr;
        }
        while (nbr)
        {
            str[--len] = (nbr % 10) + '0';
            nbr /= 10; 
        }
    }
}

char    *ft_itoa(int nbr)
{
    long n = nbr;
    int len = nbr_len(nbr);
    char *res = (char *)malloc(sizeof(char) * (len + 1));
    if (!res)
        return (NULL);
    fill_string(res, n, len);
    return (res);
}

#include <stdio.h>
int main(void)
{
    printf("%s\n", ft_itoa(55));
}
/*
#include <stdlib.h>

int nbrlen(long n)
{
    int i = 0;

    if (n == 0)
        return (1);
    if (n < 0)
        i++;
    while (n != 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}

char    *ft_itoa(int nbr)
{
    char *str;
    int len;
    long num;

    num = nbr;
    len = nbrlen(num);
    str = (char *)malloc(sizeof(char) * (len + 1));
    if (!str)
        return (NULL);
    str[len] = '\0';
    if (num < 0)
    {
        str[0] = '-';
        num = -num;
    }
    while (len > 0 && str[len - 1] != '-')
    {
        str[--len] = (num % 10) + '0';
        num /= 10;
    }
    return (str);
}

#include <stdio.h>
int main(void)
{
    printf("%s\n", ft_itoa(123));
}*/
