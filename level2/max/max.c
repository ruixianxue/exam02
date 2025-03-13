int max(int *tab, unsigned int len)
{
    int max = tab[0];
    int i = 0;

    while (i < len)
    {
        if (tab[i] > max)
            max = tab[i];
        i++;
    }
    return (max);
}
/*
#include <stdio.h>
int main(void)
{
    int tab[] = {3, 4, 6, 1, 2};
    printf("%d\n", max(tab, 5));
}*/
