void    sort_int_tab(int *tab, unsigned int size)
{
    unsigned int i = 0;
    unsigned int j = 0;
    int tmp;
	if (size <= 1)
        return ;
    while (i < size)
    {
        j = 0;
        while (j < (size - 1))
        {
            if (tab[j] > tab[j + 1])
            {
                tmp = tab[j];
                tab[j] = tab[j + 1];
                tab[j + 1] = tmp;
            }
            j++;
        }
        i++;
    }
}

#include <stdio.h>

void	ft_print_tab_int(int *tab, unsigned int size)
{
	unsigned int	idx;

	idx = 0;
	while (idx < size)
	{
		printf(" [%d] ", tab[idx]);
		idx++;
	}
}

int	main(void)
{
	int				tab[10];
	unsigned int	size;

	tab[0] = 9;
	tab[1] = 1;
	tab[2] = 7;
	tab[3] = 4;
	tab[4] = 8;
	tab[5] = 9;
	tab[6] = 2;
	tab[7] = 4;
	tab[8] = 5;
	tab[9] = 0;
	size = 10;
	ft_print_tab_int(tab, size);
	sort_int_tab(tab, size);
	printf("\n");
	ft_print_tab_int(tab, size);
	printf("\n");
	return (0);
}