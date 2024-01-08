

#include "pipex.h"

/* redirect_io:
*	Redirects the input and output file descriptors by duplicating
*	the given fds to the standard input and standard output respectively.
*/
static void	redirect_io(int input, int output, t_data *data)
{
	if (dup2(input, STDIN_FILENO) == -1)
	{
		exit_error(1, data);
	}
	if (dup2(output, STDOUT_FILENO) == -1)
	{
		exit_error(1, data);
	}
}

/* child:
*	Sets the child process's inputs and outputs depending on if it is
*	the first, middle or final child.
*	Then it parses the command it needs to execute and executes it.
*/
static void	child(t_data *data)
{
	if (data->child == 0)
		redirect_io(data->fd_in, data->pipe[1], data);
	else if (data->child == data->nb_cmds - 1)
		redirect_io(data->pipe[2 * data->child - 2], data->fd_out, data);
	else
		redirect_io(data->pipe[2 * data->child - 2], data->pipe[2 * data->child + 1], data);
	close_fds(data);
	if (data->cmd_options == NULL || data->cmd_path == NULL)
		exit_error(1, data);
	if (execve(data->cmd_path, data->cmd_options, data->envp) == -1)
		exit_error(msg(data->cmd_options[0], ": ", strerror(errno), 1), data);
}

/* parent:
*	Waits for the children processes to finish and fetches the status of the last
*	child.
*	Returns the exit status code of the last child process.
*/
static int	parent(t_data *data)
{
	pid_t	wpid;
	int		status;
	int		exit_code;

	close_fds(data);
	data->child--;
	exit_code = 1;
	while (data->child >= 0)
	{
		wpid = waitpid(data->pids[data->child], &status, 0);
		if (wpid == data->pids[data->nb_cmds - 1])
		{
			if ((data->child == (data->nb_cmds - 1)) && WIFEXITED(status))
				exit_code = WEXITSTATUS(status);
		}
		data->child--;
	}
	free(data->pipe);
	free(data->pids);
	return (exit_code);
}

/* pipex:
*	Creates a pipe and forks all necessary child processes before calling
*	the parent to wait for them to finish their tasks.
*	Returns: the last child's exit code.
*/
static int	pipex(t_data *data)
{
	int		exit_code;

	if (pipe(data->pipe) == -1)
		exit_error(msg("pipe", ": ", strerror(errno), 1), data);
	data->child = 0;
	while (data->child < data->nb_cmds)
	{
		data->cmd_options = ft_split(data->av[data->child + 2 + data->heredoc], ' ');
		if (!data->cmd_options)
			exit_error(msg("unexpected error", "", "", 1), data);
		data->cmd_path = get_cmd(data->cmd_options[0], data);
		data->pids[data->child] = fork();
		if (data->pids[data->child] == -1)
			exit_error(msg("fork", ": ", strerror(errno), 1), data);
		else if (data->pids[data->child] == 0)
			child(data);
		free_strs(data->cmd_path, data->cmd_options);
		data->child++;
	}
	exit_code = parent(data);
	if (data->heredoc == 1)
		unlink(".heredoc.tmp");
	return (exit_code);
}

/* main:
*	Launches d structure initialization and starts pipex.
*	Returns the last child's exit code as pipex's exit code.
*/
int	main(int ac, char **av, char **envp)
{
	t_data	data;
	int		exit_code;

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
		exit_error(msg("Unexpected error.", "", "", 1), &data);
	data = init(ac, av, envp);
	exit_code = pipex(&data);
	return (exit_code);
}

/*
examples of incorrect or problematic uses of pipes in shell commands. These examples are likely to result in errors or unintended behavior:

Missing Command Between Pipes:

cat file1 | | grep "pattern" > file2
In this example, there's a missing command between the two pipes (|). The shell expects a command on each side of a pipe.
Redirection Error with Pipe:

cat file1 > | grep "pattern" > file2
Here, the use of > before the pipe is incorrect. The > is a redirection operator and should not be used directly before a pipe.
Invalid File Descriptor:

cat file1 2>&1 | grep "pattern" > file3
This command is technically correct, but if file1 doesn't exist, it will result in an error. 
The 2>&1 part is redirecting standard error (stderr) to standard output (stdout), which is then piped to grep. 
If file1 is missing, cat will write an error message to stderr, which then gets redirected.
Using a Non-Existent Command:

cat file1 | nonExistentCommand > file2
If nonExistentCommand doesn't exist in your shell's path, this line will result in a "command not found" error.
Incorrect Order of Redirection and Pipe:

cat file1 > grep "pattern" | sort > file2
The redirection operator (>) is incorrectly placed before grep. The correct order is to pipe (|) the output of cat file1 to grep and then optionally to another command like sort.
Writing to a Read-Only File:

cat file1 | grep "pattern" > /path/to/readonly/file2
If file2 is a read-only file, this command will fail with a "Permission denied" error.
Missing Input File:

cat nonExistentFile | sort > file2
If nonExistentFile does not exist, cat will output an error, and sort will receive no input, resulting in an empty file2.
These examples demonstrate common mistakes in shell command syntax or logic, leading to errors or unintended results. Remember, the effectiveness of a shell command largely depends on the correctness of the command syntax and the context in which it is executed.
*/


/*
To replicate the examples of pipe misuse in your program, which is designed to replicate pipe behavior, you would structure the commands similarly to how they are misused in a shell, but within the context of how your pipex program expects arguments. Remember, your pipex program should be structured to take an input file, two commands, and an output file as arguments. Here's how you could replicate each example:

Missing Command Between Pipes:

./pipex infile "cat" "" "grep 'pattern'" outfile
Here, the second command is an empty string, representing a missing command.
Redirection Error with Pipe:

This type of error is specific to shell syntax and may not be directly replicable in your pipex program.
Invalid File Descriptor:

./pipex nonExistentFile "cat" "grep 'pattern'" outfile
If nonExistentFile doesn't exist, it should cause an error similar to a shell error when a file is missing.
Using a Non-Existent Command:

./pipex infile "nonExistentCommand" "grep 'pattern'" outfile
The first command is a non-existent command, which should result in an error.
Incorrect Order of Redirection and Pipe:

This is another shell-specific syntax issue and may not apply to your pipex program.
Writing to a Read-Only File:

./pipex infile "cat" "grep 'pattern'" /path/to/readonly/outfile
If /path/to/readonly/outfile is read-only, this should result in a "Permission denied" error.
Missing Input File:

./pipex nonExistentFile "cat" "sort" outfile
The input file doesn't exist, so cat will fail, resulting in sort receiving no input.
Since your pipex program is intended to replicate the behavior of Unix pipes, you'll need to translate these shell-specific misuse examples into the format that your program expects. It's important to remember that some shell-specific behaviors (like redirection errors) may not be directly translatable to your program's structure.

*/