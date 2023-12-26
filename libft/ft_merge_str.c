#include "libft.h"

static int seperator_counter(char **str)
{
    int ret;
    
    ret = 0;
    while(str[ret] != NULL)
    {
        ret++;
    }
    return (ret - 1);
}

static int get_new_str_len(char **str)
{
    int ret;
    int i;
    
    ret = 0;
    i = 0;
    while (str[i] != NULL)
    {
        ret += ft_strlen(str[i]);
        i++;
    }
    return (ret);
}

char *ft_merge_str(char **str, char seperator)
{
    char *ret;
    int len;
    int i;
    int j;
    int k;

    len = get_new_str_len(str) + seperator_counter(str);
    ret = malloc(sizeof(char) * (len + 1));
    ret[len] = '\0';
    i = 0;
    k = 0;
    while (str[i] != NULL)
    {
        j = 0;
        while (str[i][j] != '\0')
        {
            ret[k] = str[i][j];
            k++;
            j++;
        }
        i++;
        if (i != seperator_counter(str) + 1)
            ret[k++] = seperator;
    }
    return(ret);
}
