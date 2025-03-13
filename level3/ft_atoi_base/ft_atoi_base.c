int atoi_c(char c)
{
    if (c >= '0' && c <= '9')
        return (c - '0');
    else if (c >= 'a' && c <= 'z')
        return (c - 'a' + 10);
    else if (c >= 'A' && c <= 'Z')
        return (c - 'A' + 10);
    else
        return (-1);
}

int ft_atoi_base(const char *str, int str_base)
{
    int i = 0;
    int sign = 1;
    int res = 0;
    int c = 0;

    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    while (str[i])
    {
        c = atoi_c(str[i]);
        if (c == -1 || c >= str_base)
            break ;
        res = res * str_base + c;
        i++;
    }
    return (res * sign);
}
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi_base("12fdb3", 16));
}*/
