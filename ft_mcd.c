/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mcd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:05 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/16 08:52:24 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mcdpwd(t_myenv *myenv, int lp, char *buf)
{
	t_myenv	*pwd;

	pwd = myenv;
	while (myenv && ft_strcmp("OLDPWD", myenv->name) != 0)
		myenv = myenv->next;
	while (pwd && ft_strcmp("PWD", pwd->name) != 0)
		pwd = pwd->next;
	if (myenv && pwd)
	{
		ft_strdel(&myenv->data);
		myenv->data = pwd->data;
	}
	if (pwd)
	{
		if (lp == 'P')
		{
			pwd->data = ft_strnew(M_PATH_MAX);
			getcwd(pwd->data, M_PATH_MAX);
		}
		else
			pwd->data = ft_strdup(buf);
	}
}

int		ft_mcop(char **str, int *lp, int op)
{
	int		i;

	while (str[op] && str[op][0] == '-')
	{
		i = 1;
		if (!str[op][i])
			return (op);
		if (str[op][i] == '-')
			return (op + 1);
		while (str[op][i])
		{
			if (str[op][i] == 'L' || str[op][i] == 'P')
				*lp = str[op][i];
			else
			{
				ft_dprintf(2, "minishell: cd: -%c", str[op][i]);
				ft_dprintf(2, " invalid option\n");
				ft_dprintf(2, "cd: usage: cd [-L | -P] [dir]\n");
				return (-1);
			}
			i++;
		}
		op++;
	}
	return (op);
}

int		ft_mcdnormb(char *buf, char **str, t_myenv *myenv, int op)
{
	t_myenv	*env;

	ft_bzero(buf, M_PATH_MAX);
	env = myenv;
	if (!str[op])
	{
		if (env && (env = ft_getenv(env, "HOME")))
			ft_strcpy(buf, env->data);
	}
	else if (ft_strcmp(str[op], "-") == 0)
		ft_mcdback(str, buf, op, myenv);
	else if (str[op][0] == '/')
		ft_strcpy(buf, str[1]);
	else
		return (0);
	return (1);
}

int		ft_mcdnorm(char *buf, char *str)
{
	int		i;

	i = 0;
	if (str[0] == '~')
	{
		i = 1;
		if (str[1] && str[1] != '/')
		{
			ft_dprintf(2, "cd: no such file or directory: %s\n", str + 1);
			return (0);
		}
	}
	if (i == 0)
	{
		ft_doubleslash(buf);
		ft_strcat(buf, "/");
	}
	ft_strcat(buf, str + i);
	ft_mcdpurge(buf);
	return (1);
}

void	ft_mcd(t_myenv *myenv, char **str)
{
	char		buf[M_PATH_MAX];
	t_myenv		*env;
	int			op;
	int			lp;

	lp = 0;
	op = 1;
	env = myenv;
	if ((op = ft_mcop(str, &lp, op)) == -1)
		return ;
	if ((ft_mcdnormb(buf, str, myenv, op) == 1))
		;
	else
	{
		if (str[op][0] == '~' && (env = ft_getenv(env, "HOME")))
			ft_strcpy(buf, env->data);
		else if ((env = ft_getenv(env, "PWD")) && lp != 'P' && env->data[0])
			ft_strcpy(buf, env->data);
		else
			getcwd(buf, M_PATH_MAX);
		if (ft_mcdnorm(buf, str[op]) == 0)
			return ;
	}
	if (buf[0] && ft_mcheckp(buf) && chdir(buf) == 0)
		ft_mcdpwd(myenv, lp, buf);
}
