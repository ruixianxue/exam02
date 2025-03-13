#include "list.h"
#include <stddef.h>

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list *start = lst;
    int tmp;

    while (lst->next != NULL)
    {
        if ((*cmp)(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = start;
        }
        else
            lst = lst->next;
    }
    lst = start;
    return (lst);
}
