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