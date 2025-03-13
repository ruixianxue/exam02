#include <stdlib.h>

int *ft_rrange(int start, int end)
{
    int len = (end > start) ? end - start + 1 : start - end + 1;
    int *arr = malloc(sizeof(int) * len);
    if (!arr)
        return (NULL);
    for (int i = 0; i < len; i++)
        arr[i] = (end > start) ? end - i : end + i;
    return (arr);
}
