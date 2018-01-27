/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mexe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:21 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 10:40:39 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mfork(char *exe, char **options, char **env)
{
	pid_t	father;
	int		status;

	father = fork();
	if (father > 0)
	{
		g_son = 1;
		wait(&status);
		g_son = 0;
	}
	if (father == 0)
	{
		if (execve(exe, options, env) == -1)
		{
			ft_dprintf(2, "minishell: %s: is a directory\n", exe);
			exit(1);
		}
	}
}

int		ft_mexecve(char *path, char **option, char **cenv)
{
	char	*exe;
	char	*tmp;

	exe = NULL;
	tmp = NULL;
	if (path)
		tmp = ft_strjoin(path, "/");
	if (tmp)
	{
		exe = ft_strjoin(tmp, option[0]);
		ft_strdel(&tmp);
	}
	if (exe && (access(exe, X_OK) == 0 || access(exe, F_OK) == 0))
	{
		if (access(exe, X_OK) == 0)
			ft_mfork(exe, option, cenv);
		else
			ft_dprintf(2, "minishell: permission denied: %s\n", option[0]);
		ft_strdel(&exe);
		return (0);
	}
	ft_strdel(&exe);
	return (1);
}

void	ft_mexe(char **paths, char **options, char **cenv)
{
	int		i;
	int		commandko;

	i = -1;
	commandko = 1;
	if (options[0] && ft_strchr(options[0], '/'))
	{
		if (access(options[0], X_OK) == 0)
			ft_mfork(options[0], options, cenv);
		else if (access(options[0], F_OK) == 0)
			ft_dprintf(2, "minishell: permission denied: %s\n", options[0]);
		else
			ft_dprintf(2, "minishell: command not found: %s\n", options[0]);
	}
	else if (paths)
	{
		while (paths[++i] && commandko != 0)
			commandko = ft_mexecve(paths[i], options, cenv);
		if (commandko && options && options[0])
			ft_dprintf(2, "minishell: command not found: %s\n", options[0]);
	}
	else
		ft_dprintf(2, "minishell: command not found: %s\n", options[0]);
}
