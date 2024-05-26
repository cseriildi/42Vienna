/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:01:26 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/26 15:20:27 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <errno.h>
# include <stdio.h>
# include <sys/wait.h>

# include "libft/libft.h"

typedef struct s_var
{
	pid_t	pid;
	int		pipe_fd[2];
	char	*infile;
	int		infile_fd;
	char	*outfile;
	int		outfile_fd;
	char	**commands;
	int		cmd_count;
	char	*absolut_cmd;
	char	*cmd;
	char	**args;
	int		status;
	char	**path;
	char	**env;

}	t_var;

//utils
void	array_free(char ***arr);
char	*ft_strjoin2(char *str1, char *str2, char *delimiter);
char	*error_message(int code);
void	elegant_exit(t_var *data, int error_code);

//parsing
void	exec_command(t_var *data, int cmd_index);
char	*find_path(t_var *data);
void	parse_input(t_var *data, int count, char **params, char **env);

//main
void	first_command(t_var *data);
void	last_command(t_var *data);

//ERROR CODES
# define EXIT_SUCCESS 0  // Successful execution
# define EXIT_FAILURE 1  // General error

# define ERROR_MISUSE 2  // Incorrect usage
# define CANNOT_OPEN_FILE 3 // Unable to open the file
# define MALLOC_FAIL 4  // Memory allocation failure
# define MISSING_PATH 5  // PATH environment variable is missing
# define PIPE_FAIL 6  // pipe() system call failure
# define DUP2_FAIL 7  // dup2() system call failure
# define FORK_FAIL 8  // fork() system call failure

# define ERROR_CANNOT_EXECUTE 126  // Command found but is not executable
# define COMMAND_NOT_FOUND 127  // Command not found

#endif