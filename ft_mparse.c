/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mparse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:26 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/27 08:18:59 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_mpath(t_myenv *env)
{
	while (env)
	{
		if (ft_strcmp("PATH", env->name) == 0)
			return (ft_strsplit(env->data, ':'));
		env = env->next;
	}
	return (NULL);
}

int		ft_parsemyop(t_myenv **env, char **option)
{
	int		i;

	i = 1;
	if (ft_strcmp("exit", option[0]) == 0)
	{
		if (*env)
			ft_freemyenv(*env);
		exit(1);
	}
	if (ft_strcmp("env", option[0]) == 0)
		ft_menv(env, option);
	else if (ft_strcmp("setenv", option[0]) == 0)
		ft_msetenv(env, option, &i);
	else if (ft_strcmp("unsetenv", option[0]) == 0)
		ft_munsetenv(env, option, &i);
	else if (ft_strcmp("cd", option[0]) == 0)
		ft_mcd(*env, option);
	else if (ft_strcmp("echo", option[0]) == 0)
		ft_mecho(option);
	else
		return (0);
	return (1);
}

void	ft_mrecur(t_myenv **env, char **option, t_myenv **tmpenv)
{
	char	**paths;
	char	**cenv;

	paths = NULL;
	cenv = NULL;
	if (*option && ft_parsemyop(env, option) == 0)
	{
		if (*env)
			paths = ft_mpath(*env);
		cenv = ft_menvtochar(*tmpenv);
		ft_mexe(paths, option, cenv);
		if (paths)
			ft_strdeltab(&paths);
		if (cenv)
			ft_strdeltab(&cenv);
	}
}

void	ft_tabtospace(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t')
			str[i] = ' ';
		i++;
	}
}

void	ft_mparse(t_myenv **env)
{
	char	*str;
	char	**option;
	char	**cmdp;
	int		i;

	i = -1;
	option = NULL;
	cmdp = NULL;
	if (get_next_line(0, &str) == -1)
		exit(1);
	if (str)
	{
		ft_tabtospace(str);
		cmdp = ft_strsplit(str, ';');
		while (cmdp[++i])
		{
			option = ft_strsplit(cmdp[i], ' ');
			ft_mrecur(env, option, env);
			ft_strdeltab(&option);
		}
	}
	if (cmdp)
		ft_strdeltab(&cmdp);
	if (str)
		ft_strdel(&str);
}
