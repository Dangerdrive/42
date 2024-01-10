/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-alen <fde-alen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 22:36:53 by fde-alen          #+#    #+#             */
/*   Updated: 2024/01/09 22:22:55 by fde-alen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "pipex.h"

/* 
 * get_env_path:
 *   Searches for the "PATH=" entry in the environment variable array.
 *
 * Parameters:
 *   envp - Environment variables array.
 *
 * Returns:
 *   A dynamically allocated string containing the PATH environment variable (excluding "PATH=").
 *   Returns NULL if the PATH variable is not found or if memory allocation fails.
 *
 * Notes:
 *   - The function iterates through the envp array to find the entry starting with "PATH=".
 *   - Upon finding the PATH entry, it allocates a new string containing just the paths (removing "PATH=").
 */
static char *get_env_path(char **envp)
{
    char *path;
    int i;

    i = 0;
    path = NULL;
    while (envp[i] != NULL && envp[i][0] != '\0')
    {
        path = ft_strnstr(envp[i], "PATH=", 5);
        if (path)
        {
            path = ft_substr(path, 5, ft_strlen(path));
            break;
        }
        i++;
    }
    return (path);
}

/* 
 * make_usable_paths:
 *   Appends a '/' character at the end of each path string in the array.
 *
 * Parameters:
 *   paths - Array of path strings.
 *
 * Returns:
 *   The modified array of path strings with a '/' appended to each.
 *
 * Notes:
 *   - Iterates through the paths array and appends a '/' to each string.
 *   - Uses dynamic memory allocation for the new strings; the original strings are freed.
 */
static char **make_usable_paths(char **paths)
{
    int i;
    char *tmp;

    i = 0;
    tmp = NULL;
    while (paths[i])
    {
        tmp = paths[i];
        paths[i] = ft_strjoin(paths[i], "/");
        //free_strs(tmp, NULL);
        free(tmp);
        tmp = NULL;
        i++;
    }
    return (paths);
}




/* 
 * get_env_paths:
 *   Retrieves the PATH environment variable and splits it into individual paths.
 *
 * Parameters:
 *   envp - Environment variables array.
 *
 * Returns:
 *   An array of strings, each representing a path from the PATH environment variable.
 *   Returns NULL if the PATH variable is not found or if memory allocation fails.
 *
 * Notes:
 *   - Calls get_env_path to obtain the PATH variable.
 *   - Splits the PATH string into individual paths using ':' as the delimiter.
 *   - Calls make_usable_paths to append a '/' to each path string.
 */
static char **get_env_paths(char **envp)
{
    char *env_path_str;
    char **paths;

    env_path_str = get_env_path(envp);
    if (!env_path_str)
        return (NULL);
    paths = ft_split(env_path_str, ':');
    //free_strs(env_path_str, NULL);
    free(env_path_str);
    env_path_str = NULL;    
    if (!paths)
        return (NULL);
    paths = make_usable_paths(paths);
    if (!paths)
        return (NULL);
    return (paths);
}


/* 
 * get_cmd_path:
 *   Searches for the specified command in the given paths.
 *
 * Parameters:
 *   cmd - The command to find.
 *   paths - Array of path strings.
 *
 * Returns:
 *   A dynamically allocated string containing the full path to the command if found.
 *   Returns NULL if the command is not found in the given paths.
 *
 * Notes:
 *   - Iterates through each path and checks if the command exists and is executable in that path.
 *   - If found, returns the full path to the command.
 *   - If the command is not found, or if memory allocation fails, returns NULL.
 */
static char *get_cmd_path(char *cmd, char **paths)
{
    int i;
    char *cmd_path;

    cmd_path = NULL;
    i = 0;
    while (paths[i])
    {
        cmd_path = ft_strjoin(paths[i], cmd);
        if (!cmd_path)
        {
            free_strs(NULL, paths);
            exit_error(msg("unexpected error", "", "", 1), NULL);
        }
        if (access(cmd_path, F_OK | X_OK) == 0)
            return (cmd_path);
        //free_strs(cmd_path, NULL);
        free(cmd_path);
        cmd_path = NULL;
        i++;
    }
    return (NULL);
}


/* 
 * get_cmd:
 *   Retrieves the full path of a given command from the environment paths.
 *
 * Parameters:
 *   cmd - The command to find.
 *   data - Pointer to a t_data structure containing environment variables.
 *
 * Returns:
 *   A dynamically allocated string containing the full path to the command.
 *   Returns NULL if the command is not found in the environment paths.
 *
 * Notes:
 *   - First checks if the command is directly accessible (e.g., absolute path or in the current directory).
 *   - If not, it retrieves the environment paths and searches for the command in them.
 *   - If the command is not found, a "command not found" message is displayed.
 */
char *get_cmd(char *cmd, t_data *data)
{
    char **env_paths;
    char *cmd_path;

    if (access(cmd, F_OK | X_OK) == 0)
        return (ft_strdup(cmd));
    env_paths = get_env_paths(data->envp);
    if (!env_paths)
        return (NULL);
    cmd_path = get_cmd_path(cmd, env_paths);
    if (!cmd_path)
        msg("command not found", ": ", data->av[data->child + 2], 1);
    free_strs(NULL, env_paths);
    return (cmd_path);
}
