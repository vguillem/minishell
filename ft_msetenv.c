/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_msetenv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:11:56 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/20 08:11:14 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mnewenv(t_myenv **myenv, char *str, int j)
{
	t_myenv	*tmp;

	tmp = *myenv;
	while (tmp && tmp->next)
		tmp = tmp->next;
	if (*myenv)
	{
		tmp->next = (t_myenv *)ft_memalloc(sizeof(t_myenv));
		tmp = tmp->next;
	}
	else
	{
		*myenv = (t_myenv *)ft_memalloc(sizeof(t_myenv));
		tmp = *myenv;
	}
	if (tmp)
	{
		tmp->name = ft_strsub(str, 0, j);
		tmp->data = ft_strdup(str + j + 1);
		tmp->next = NULL;
	}
}

void	ft_mnewset(t_myenv *myenv, char *str, int j)
{
	if (myenv)
	{
		if (myenv->data)
			ft_strdel(&myenv->data);
		myenv->data = ft_strdup(str + j + 1);
	}
}

void	ft_msetenv(t_myenv **myenv, char **str, int *i)
{
	int		j;
	char	*tmp;
	t_myenv	*env;

	tmp = NULL;
	env = *myenv;
	while (str[*i] && ft_strchr(str[*i], '='))
	{
		j = 0;
		while (str[*i][j] != '=')
			j++;
		if (j > 0)
		{
			env = *myenv;
			while (env && env->name && ft_strncmp(str[*i], env->name, j) != 0)
				env = env->next;
			if (!env)
				ft_mnewenv(myenv, str[*i], j);
			else
				ft_mnewset(env, str[*i], j);
		}
		(*i)++;
	}
}
