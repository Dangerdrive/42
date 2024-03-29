
#ifndef PIPEX_H
# define PIPEX_H

/* to write, read, close, access, pipe, dup, dup2, execve, fork */
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>

/* malloc, free, exit */
# include <stdlib.h>

/* open, unlink */
# include <fcntl.h>

/* waitpid, wait */
# include <sys/wait.h>

/* strerror */
# include <string.h>

/*to perror*/
# include <stdio.h>

/* to get_next_line */
//# include "../gnl/get_next_line.h"

# define ERR_INFILE "Infile"
# define ERR_OUTFILE "Outfile"
# define ERR_INPUT "Invalid number of arguments.\n"
# define ERR_PIPE "Pipe"
# define ERR_CMD "Command not found\n"

typedef struct s_pipex
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
	ft_strncmp.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strlcpy.c \
	get_next_line.c \
	get_next_line_utils.c
	ft_strncmp.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strlcpy.c \
	get_next_line.c \
	get_next_line_utils.c
	ft_strncmp.c \
	ft_strnstr.c \
	ft_substr.c \
	ft_strlcpy.c \
	get_next_line.c \
	get_next_line_utils.c
	char	*cmd_path;
	// pid_t	pid1;
	// pid_t	pid2;
	// int		fd[2];
	// int		infile;
	// int		outfile;
	// char	*paths;
	// char	**cmd_paths;
	// char	**cmd_args;
	// char	*cmd;
}t_pipex;

/* childs.c */
void	first_child(t_pipex pipex, char *argv[], char *envp[]);
void	second_child(t_pipex pipex, char *argv[], char *envp[]);

/* free.c */
void	parent_free(t_pipex *pipex);
void	child_free(t_pipex *pipex);

/* error.c */
void	msg_error(char *err);
int		msg(char *err);

/* funcions */
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);

#endif