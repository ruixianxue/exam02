#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
    if (ac == 3)
    {
        int a = atoi(av[1]);
        int b = atoi(av[2]);
        int i;

        if (a > b)
            i = b;
        else
            i = a;
        while (a % i != 0 || b % i != 0 )
            i--;
        printf("%d", i);
    }
    printf("\n");
    return 0;
}
