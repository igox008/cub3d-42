#include "./includes/cub3d.h"

int ft_strlen(const char *str)
{
    int i = 0;
    if (!str)
        return (0);
    while (str[i])
        i++;
    return (i);
}

bool    ft_strcmp(char *s1,char  *s2)
{
    int i = 0;
    while (s1[i] && s2[i])
    {
        if (s1[i] != s2[i])
            return (0);
        i++;
    }
    return (1);
}

bool    openFile(char *filename, int *fd)
{
    *fd = open(filename,O_RDWR);
    if ((*fd) == -1)
        return (0);
    return (1);
}

bool verfBorder(char *str)
{
    int i = 0;
    while (str[i] && str[i] != '\n')
    {
        if (str[i] != 49)
            return (0);
        i++;
    }
    return (1);
}

bool verfBorderV2(char *str)
{
    if (!str)
        return (0);
    printf("----------[%c]---------\n",str[ft_strlen(str) - 2]);
    // exit(0);
    // if (str[ft_strlen(str) - 2] != 49 || str[0] != 49)
    //     return (0);
    return (1);
}


bool    checkContentFile(int  *fd)
{
    char *str;
    char *str1;

    str = get_next_line(*fd);
    if (!str || !verfBorder(str))
        return (0);
    while (str && (str1 = get_next_line(*fd)))
    {
        if (!verfBorderV2(str))
            return (0);
        str = str1;
    }
    if (!verfBorder(str1))
        return (0);
    return (1);
}

bool check_extension(char *filename)
{
    if (!ft_strcmp(filename + ft_strlen(filename) - 4,".cub"))
        return (0);
    return (1);
}

bool check_parce(char *str,int *fd)
{
    if (!check_extension(str))
        return (0);
    if (!openFile(str, fd))
        return (0);
    if (!checkContentFile(fd))
        return (0);
    return (1);
}

int main(int argc, char **argv)
{
    int fd;
    if (argc != 2)
        return (printf("Error\n"), 1);
    if (!check_parce(argv[1], &fd))
        return (printf("Error\n"), 1);
    printf("OK!\n");
}