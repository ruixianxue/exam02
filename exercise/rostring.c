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
        while (str[i] && ft_isspace(str[i]))
            i++;
        if (str[i] && !ft_isspace(str[i]))
        {
            if (first_word_length == 0)
            {
                while (str[i] && !ft_isspace(str[i]))
                {
                    first_word_length++;
                    i++;
                }
            }
            else
            {
                while (str[i] && !ft_isspace(str[i]))
                {
                    write(1, &str[i], 1);
                    i++;
                }
                write(1, " ", 1);
            }
        }
    }
    i = 0;
    while (str[i] && ft_isspace(str[i]))
        i++;
    while (first_word_length--)
        write(1, &str[i++], 1); 
}

int main(int ac, char **av)
{
    if (ac > 1)
        rostring(av[1]);
    write(1, "\n", 1);
}