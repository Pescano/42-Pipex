/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: paescano <paescano@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:39:07 by paescano          #+#    #+#             */
/*   Updated: 2022/12/03 18:05:31 by paescano         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_exec(char *full_command, char **envp)
{
	int		i;
	char	**command_flags;
	char	**paths;
	char	*route;

	command_flags = ft_split(full_command, ' ');
	paths = ft_path_from_envp(envp);
	i = 0;
	while (paths[i])
	{
		route = ft_strjoin(paths[i], command_flags[0]);
		if (access(route, F_OK) == 0)
		{
			ft_free(paths);
			execve(route, command_flags, envp);
			free(route);
			break ;
		}
		free(route);
		i++;
	}
	ft_free(command_flags);
	ft_error_exit("Command not found");
}

void	ft_change_in(int pipes, int fd)
{
	if (dup2(pipes, STDOUT_FILENO) == -1)
		ft_error_exit("ERROR dup2 in");
	if (dup2(fd, STDIN_FILENO) == -1)
		ft_error_exit("ERROR dup2 in");
	close(pipes);
	close(fd);
}

void	ft_change_out(int pipes, int fd)
{
	if (dup2(fd, STDOUT_FILENO) == -1)
		ft_error_exit("ERROR dup2 out");
	if (dup2(pipes, STDIN_FILENO) == -1)
		ft_error_exit("ERROR dup2 out");
	close(pipes);
	close(fd);
}

void	ft_pipex(char **argv, char **envp, int *pipes)
{
	int		fd[2];
	pid_t	pid_child;

	pid_child = fork();
	if (pid_child < 0)
		ft_error_exit("FORK ERROR");
	if (!pid_child)
	{
		fd[0] = open(argv[1], O_RDONLY);
		if (fd[0] < 0)
			ft_error_exit("pipex: input");
		close(pipes[0]);
		ft_change_in(pipes[1], fd[0]);
		ft_exec(argv[2], envp);
	}
	else
	{
		fd[1] = open(argv[4], O_CREAT | O_WRONLY | O_TRUNC, 0644);
		if (fd[1] < 0)
			ft_error_exit("pipex: input");
		close(pipes[1]);
		ft_change_out(pipes[0], fd[1]);
		ft_exec(argv[3], envp);
	}
}

int	main(int argc, char **argv, char **envp)
{
	int		pipes[2];

	if (argc != 5)
	{
		ft_error_exit_manual("Error: wrong count of arguments, only 4");
		return (1);
	}
	if (pipe(pipes) == -1)
		ft_error_exit("PIPE ERROR");
	ft_pipex(argv, envp, pipes);
	return (0);
}
