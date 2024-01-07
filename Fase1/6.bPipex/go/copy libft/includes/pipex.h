
#ifndef PIPEX_H
# define PIPEX_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <sys/wait.h>
# include <string.h>
# include <errno.h>
# include "libft.h"

/*  Data    */
typedef struct s_data
{
	char	**envp;
	char	**av;
	int		ac;
	int		heredoc;
	int		fd_in;
	int		fd_out;
	int		*pipe;
	int		nb_cmds;
	int		child;
	int		*pids;
	char	**cmd_options;
	char	*cmd_path;
}		t_data;

/*  initialization.c    */
t_data	init(int ac, char **av, char **envp);

/*  env_parsing.c   */
char	*get_cmd(char *cmd, t_data *data);

/*  utils.c */
void	exit_error(int error_status, t_data *data);
int		msg(char *str1, char *str2, char *str3, int erno);
void	close_fds(t_data *data);
void	free_strs(char *str, char **strs);


/* file_handler.c */
void	get_input_file(t_data *data);
void	get_output_file(t_data *data);
void	get_heredoc(t_data *data);

/*functions from libft*/
/*ft_putchar_fd
ft_putendl_fd
ft_putstr_fd
ft_split
ft_strjoin
ft_strlen
ft_strncmp
ft_strnstr
ft_substr
ft_strlcpy
ft_strdup
get_next_line*/

#endif
