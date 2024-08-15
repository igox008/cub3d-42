#ifndef G_COLLECTOR_H
# define G_COLLECTOR_H
# include <stdlib.h>

typedef struct s_col
{
	void			*ptr;
	struct s_col	*next;
}t_col;

typedef enum e_call
{
	FREE,
	FREE_S,
	MALLOC,
	MALLOC_S,
	GET_SIZE
}t_call;


void	*g_malloc(size_t size, t_call call);

#endif