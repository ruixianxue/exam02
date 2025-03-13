#include <unistd.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t');
}

void    rostring(char *str)
{
    int i = 0;
    int first_word_length = 0;

    while (str[i])
    {
        //跳过空格
        while (ft_isspace(str[i]))
            i++;
        //记录第一个word
        if (str[i] && !ft_isspace(str[i]))
        {
            //如果是第一个word
            if (first_word_length == 0)
                while (str[i] && !ft_isspace(str[i]))
                {
                    //计算第一个word长度
                    first_word_length++;
                    i++;
                }
            else
            {
                //如果不是第一个word则打印这个word
                while (str[i] && !ft_isspace(str[i]))
                {
                    write(1, &str[i], 1);
                    i++;
                }
                //打印一个空格
                write(1, " ", 1);
            }
        }
    }
    i = 0;
    //从头开始跳过空格
    while (ft_isspace(str[i]))
        i++;
    //打印第一个word
    while (first_word_length--)
        write(1, &str[i++], 1);
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
}
