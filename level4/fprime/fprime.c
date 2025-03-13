#include <stdio.h>
#include <stdlib.h>

void    fprime(int n)
{
    int i = 2;

    if (n == 1)
    {
        printf("1");
        return ;
    }
    while (i <= n)
    {
        if (n % i == 0)
        {
            printf("%d", i);
            n /= i;
            if (n > 1)
                printf("*");
        }
        else
            i++;
    }
}

int main(int ac, char **av)
{
    int n;

    if (ac == 2)
    {
        n = atoi(av[1]);
        fprime(n);
    }
    printf("\n");
}
