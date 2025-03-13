typedef struct  s_list
{
    struct s_list   *next;
    void            *data;
}   t_list;

void    ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
    while (begin_list)
    {
        if (begin_list->data)
            f(begin_list->data);
        begin_list = begin_list->next;
    }
}

#include <stdio.h>
void    print_int(void *data)
{
    int a = *(int *)data;
    printf("%d", a);
}

int main(void)
{
    t_list l1, l2, l3;
    int a = 3, b = 6, c = 9;

    l1.data = &a;
    l1.next = &l2;
    l2.data = &b;
    l2.next = &l3;
    l3.data = &c;
    l3.next = NULL;
    ft_list_foreach(&l1, print_int);
    return 0;
}
