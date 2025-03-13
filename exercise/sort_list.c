typedef struct s_list
{
	int				data;
	struct s_list	*next;
}	t_list;

t_list  *sort_list(t_list *lst, int (*cmp)(int, int))
{
    t_list  *begin;
    int tmp;
    begin = lst;
    while (lst && lst->next)
    {
        if (cmp(lst->data, lst->next->data) == 0)
        {
            tmp = lst->data;
            lst->data = lst->next->data;
            lst->next->data = tmp;
            lst = begin;
        }
        else
            lst = lst->next;
    }
    lst = begin;
    return (lst);
}

#include <stdio.h>
#include <stdlib.h>

void    print_list(t_list *lst)
{
    while (lst)
    {
        printf("%d ", lst->data);
        lst = lst->next;
    }
}

int ascending(int a, int b)
{
	return (a <= b);
}

int main()
{
    t_list l1, l2, l3;
    int a = 12, b = 6, c = 9;

    l1.data = a;
    l1.next = &l2;
    l2.data = b;
    l2.next = &l3;
    l3.data = c;
    l3.next = NULL;
    print_list(&l1);
    sort_list(&l1, ascending);
    print_list(&l1);
}