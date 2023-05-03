#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
// # define MAX_INT 2147483647
// # define MIN_INT -2147483648

# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>

// typedef struct s_list
// {
// 	void			*content;
// 	struct s_list	*next;
// }	t_list;

char *get_next_line(int fd);

#endif