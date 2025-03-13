#include <stdlib.h>
#include <stdio.h>

int main(int ac, char **av)
{
    int i = 2;
    int n;
    int first = 1;

    if (ac == 2)
    {
        n = atoi(av[1]);
        if (n == 1)
            printf("1");
        while (i <= n)
        {
            if (n % i == 0)
            {
                if (!first)
                    printf("*");
                printf("%d", i);
                first = 0;
                n = n / i;
            }
            else
                i++;
        }
    }
    printf("\n");
}