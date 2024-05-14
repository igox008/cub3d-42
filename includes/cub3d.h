#ifndef CUB3D_H
#define CUB3D_H

# include <stdbool.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "./structs.h"
# include <limits.h>
 # ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int     ft_strlen(const char *str);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_strjoin(char const *s1, char const *s2);
#endif