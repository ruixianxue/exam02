#include <stdlib.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\n' || c == '\t');
}

int count_words(char *str)
{
    int count = 0;

    while (*str)
    {
        //跳过空格
        while (*str && ft_isspace(*str))
            str++;
        //遇到第一个非空格，count++，然后走完所有非空格直到下一个空格
        if (*str && !ft_isspace(*str))
        {
            count++;
            while (*str && !ft_isspace(*str))
                str++;
        }
    }
    return (count);
}

char    *malloc_word(char *str)
{
    char *word;//要被malloc的word
    int i = 0;
    //遍历这个word得到长度
    while (str[i] && !ft_isspace(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (!word)
        return (NULL);
    i = 0;
    //从word开头一个一个字符复制到word来
    while (str[i] && !ft_isspace(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    //最后一位设为null
    word[i] = '\0';
    return (word);
}

char    **ft_split(char *str)
{
    char    **arr = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
    int i = 0;

    while (*str)
    {
        //跳过空格
        while (*str && ft_isspace(*str))
            str++;
        //遇到第一个非空格， malloc一个word，走完所有非空格直到下一个空格
        if (*str && !ft_isspace(*str))
        {
            arr[i] = malloc_word(str);
            i++;
            while (*str && !ft_isspace(*str))
                str++;
        }
    }
    //最后一个设为null
    arr[i] = NULL;
    return (arr);
}
/*
#include <stdio.h>
int main(void)
{
    char    **res;

    res = ft_split(" hello world ! \n hi ");
    int i = 0;
    while (res[i])
        printf("%s\n", res[i++]);
}*/
