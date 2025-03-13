int ft_atoi(const char *str)
{
    int sign = 1;
    int res = 0;
    int i = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32 || str[i] == '+')
        i++;
    while (str[i] == '-')
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
/*
#include <stdio.h>
int main(void)
{
    printf("%d\n", ft_atoi("    -123"));
}*/
