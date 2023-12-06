
#include "pipex.h"

// int	main(int argc, char **argv)
// {
// 	(void)argc;
// 	(void)argv;
// 	return (0);
// }


// #include <stdio.h>
// #include <fcntl.h>
// #include <unistd.h>

// int	main(int argc, char **argv)
// {
//	 int fd;

//	 fd = open(argv[1], O_WRONLY | O_CREAT, 1777);
//	 dup2(fd, STDOUT_FILENO);  // (newfd, oldfd) - redirecting stdout(oldfd) to file(newfd)
//	 close(fd); //fd no longer needed - the dup'ed handles are sufficient
//	 printf(argv[2]);

//	 return (0);
// }

// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//	 if (access("example.txt", X_OK | R_OK) != -1)
//		 printf("I have permission\n");
//	 else
//		 printf("I don't have permission\n");

//	 return (0);
// }

// #include <unistd.h>
// #include <stdio.h>

// int main()
// {
//	 char *args[3];

//	 args[0] = "ls";
//	 args[1] = "-l";
//	 args[2] = NULL;
//	 execve("/bin/ls", args, NULL);
//	 printf("This line will not be executed.\n");

//	 return (0);
// }


// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main()
// {
// 	printf("PID: %d\n", getpid());
//	 int pid;

//	 pid = fork();
//	 if (pid == -1)
//	 {
//		 perror("fork");
//		 exit(EXIT_FAILURE);
//	 }

//	 if (pid == 0) // child process
//		 printf("This is the child process. (pid: %d)\n", getpid());
//	 else
//		 printf("This is the parent process. (pid: %d)\n", getpid());

//	 return (0);
// }

// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>

// int main()
// {
//	 int fd[2];
//	 pid_t pid;
//	 char buffer[13];

//	 if (pipe(fd) == -1)
//	 {
//		 perror("pipe");
//		 exit(EXIT_FAILURE);
//	 }

//	 pid = fork();
//	 if (pid == -1)
//	 {
//		 perror("fork");
//		 exit(EXIT_FAILURE);
//	 }

//	 if (pid == 0)
//	 {
//		 close(fd[0]); // close the read end of the pipe
//		 write(fd[1], "Hello parent!", 13);
//		 close(fd[1]); // close the write end of the pipe
//		 exit(EXIT_SUCCESS);
//	 }
//	 else
//	 {
//		 close(fd[1]); // close the write end of the pipe
//		 read(fd[0], buffer, 14);
//		 close(fd[0]); // close the read end of the pipe
//		 printf("Message from child: '%s'", buffer);
//		 exit(EXIT_SUCCESS);
//	 }
// }


// #include <stdio.h>
// #include <unistd.h>

// int main()
// {
//	 if (unlink("example.txt") == 0)
//		 printf("File successfully deleted");
//	 else
//		 printf("Error deleting file");
//	 return (0);
// }

check_args

void	init_pipex(t_pipe	*pipex)
{
	
}


int	main(int argc, char **argv)
{
	t_pipex	*pipex;
	int	id;

	if (argc != 5)
	{
		perror("args\n");
		exit(EXIT_FAILURE);
	}
	pipex = malloc(sizeof(t_pipex));
	if (!pipex)
	{
		perror("malloc\n");
		exit(EXIT_FAILURE);
	}
	pipe(pipex->fd);
	id = fork();
	if (id == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	 if (id == 0) // child process - cmd1
	 {
		dup2(fd, STDOUT_FILENO)
		close(fd[0]); // close the read end of the pipe
		// write(fd[1], "Hello parent!", 13);
		close(fd[1]); // close the write end of the pipe
		exit(EXIT_SUCCESS);
	 }
	 else // parent process - cmd2
	 {
		close(fd[1]); // close the write end of the pipe
		//read(fd[0], buffer, 13);
		close(fd[0]); // close the read end of the pipe
		//printf("Message from child: '%s'\n", buffer);
		exit(EXIT_SUCCESS);
	 }
	
	init_pipex(pipex);
	check_args(argc, argv);
	ft_parse_cmds()
	ft_parse_args()
	while (cmds)
		ft_exec()
}


// $> ./pipex infile "ls -l" "wc -l" outfile
// Should behave like: < infile ls -l | wc -l > outfile
// $> ./pipex infile "grep a1" "wc -w" outfile
// Should behave like: < infile grep a1 | wc -w > outfile
// III.2
// Requirements
// Your project must comply with the following rules:
// • You have to turn in a Makefile which will compile your source files. It must not
// relink.
// • You have to handle errors thoroughly. In no way your program should quit unex-
// pectedly (segmentation fault, bus error, double free, and so forth).
// • Your program mustn’t have memory leaks.
// • If you have any doubt, handle the errors like the shell command:
// < file1 cmd1 | cmd2 > file2

static t_pipex	clean_init(void)
{
	t_pipex	pipex;

	pipex.envp = NULL;
	pipex.ac = -1;
	pipex.av = NULL;
	pipex.heredoc = 0;
	pipex.fd_in = -1;
	pipex.fd_out = -1;
	pipex.pipe = NULL;
	pipex.nb_cmds = -1;
	pipex.child = -1;
	pipex.pids = NULL;
	pipex.cmd_options = NULL;
	pipex.cmd_path = NULL;
	return (pipex);
}

int validate_args(int ac, char **av, t_pipex *pipex)
{
    if (ac < 5)
	{
        if (ac >= 2 && !ft_strncmp("here_doc", av[1], 9))
            return (msg("Usage: ",
                        "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.",
                        "", 1));
        return (msg("Usage: ",
                    "./pipex file1 cmd1 cmd2 ... cmdn file2.", "", 1));
    } 
	else if (ac < 6 && !ft_strncmp("here_doc", av[1], 9))
        return (msg("Usage: ",
                    "./pipex here_doc LIMITER cmd1 cmd2 ... cmdn file2.", "", 1));
    if (!envp || envp[0][0] == '\0')
        exit_error(msg("Unexpected error.", "", "", 1), &pipex);
}

int	main(int ac, char** av, char** envp)
{
	t_pipex	pipex;

	if (!validate_args(ac, av, &pipex))
		return (1);
	pipex = 


	
}