/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/12 14:01:26 by cseriildii        #+#    #+#             */
/*   Updated: 2024/05/23 18:02:11 by icseri           ###   ########.fr       */
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

void	exec_command(char *cmd, char **env);
void	array_free(char ***arr);
char	*ft_strjoin_with_delimiter(char *str1, char *str2, char *delimiter);
void	elegant_exit(char *error_msg, char **arr1_to_free, char **arr2_to_free);
void	first_command(int *pipe_fd, char *infile, char *cmd, char **env);
void	last_command(int *pipe_fd, char *outfile, char *cmd, char **env);

typedef struct s_cmd
{
	char	*cmd;
	char	**args;
	char	*path;

}	t_cmd;

#endif