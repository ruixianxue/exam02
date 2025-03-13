#include <stdlib.h>

int ft_isspace(char c)
{
    return (c == ' ' || c == '\t' || c == '\n');
}

int count_words(char *str)
{
    int count = 0;

    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
        {
            count++;
            while (*str && !ft_isspace(*str))
                str++;
        }
    }
    return (count);
}

char *malloc_word(char *str)
{
    int i = 0;
    char *word;


    while (str[i] && !ft_isspace(str[i]))
        i++;
    word = (char *)malloc(sizeof(char) * (i + 1));
    if (word == NULL)
        return (NULL);
    word[i] = '\0';
    i = 0;
    while (str[i] && !ft_isspace(str[i]))
    {
        word[i] = str[i];
        i++;
    }
    return (word);
}

char    **ft_split(char *str)
{
    int i;
    int len;
    char **arr;

    len = count_words(str);
    arr = (char **)malloc(sizeof(char *) * (len + 1));
    if (arr == NULL)
        return (NULL);
    arr[len] = NULL;
    i = 0;
    while (*str)
    {
        while (*str && ft_isspace(*str))
            str++;
        if (*str && !ft_isspace(*str))
        {
            arr[i] = malloc_word(str);
            i++;
            while (*str && !ft_isspace(*str))
                str++;
        }
    }
    return (arr);
}

#include <stdio.h>

int main()
{
    char str[] = " hello ho\n hi world    ";
    char **word = ft_split(str);
    int i = 0;
    while (word[i])
    {
        printf("%s\n", word[i]);
        i++;
    }
}