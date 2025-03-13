#include <unistd.h>

void    rev_wstr(char *str, int first)
{
    int i = 0;
    int start = 0;

    if (str[i])
    {
        //跳过空格
        while (str[i] && (str[i] == ' ' || str[i] == '\t'))
            i++;
        if (!str[i])
           return ;
        //start是word的开始
        start = i;
        //跳过word，把剩下的部分传入迭代
        while (str[i] && str[i] != ' ' && str[i] != '\t')
            i++;
        rev_wstr(&str[i], 0);
        //打印这个word
        write(1, &str[start], i - start);
        if (!first)
            write(1, " ", 1);
    }
}

int main(int ac, char **av)
{
    if (ac == 2)
        rev_wstr(av[1], 1);
    write(1, "\n", 1);
}
