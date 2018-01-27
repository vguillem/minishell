/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_myenv.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:39 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/07 16:40:09 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_envinit(char *env, t_myenv *myenv)
{
	size_t	j;

	j = 0;
	while (env[j] && env[j] != '=')
		j++;
	myenv->name = ft_strsub(env, 0, j);
	myenv->data = ft_strdup(env + j + 1);
	myenv->next = NULL;
}

void	ft_mcpmyenv(t_myenv *myenv, t_myenv **tmpenv)
{
	t_myenv	*tmp;
	t_myenv	*tmp2;
	int		i;

	i = 0;
	*tmpenv = NULL;
	tmp = *tmpenv;
	tmp2 = NULL;
	while (myenv)
	{
		tmp2 = (t_myenv *)ft_memalloc(sizeof(t_myenv));
		if (!(*tmpenv))
			*tmpenv = tmp2;
		else if (tmp)
			tmp->next = tmp2;
		tmp = tmp2;
		tmp->name = ft_strdup(myenv->name);
		tmp->data = ft_strdup(myenv->data);
		tmp->next = NULL;
		myenv = myenv->next;
	}
}

void	ft_freemyenv(t_myenv *myenv)
{
	t_myenv	*tmp;

	tmp = myenv;
	while (tmp)
	{
		myenv = tmp->next;
		if (tmp->data)
			ft_strdel(&tmp->data);
		if (tmp->name)
			ft_strdel(&tmp->name);
		ft_memdel((void **)&tmp);
		tmp = myenv;
	}
}

void	ft_myenv(char **env, t_myenv **begin)
{
	t_myenv	*myenv;
	t_myenv	*tmp;
	int		i;

	i = -1;
	tmp = NULL;
	if (*env)
	{
		while (env && env[++i])
		{
			myenv = (t_myenv *)ft_memalloc(sizeof(t_myenv));
			if (!(*begin))
				*begin = myenv;
			else if (tmp)
				tmp->next = myenv;
			tmp = myenv;
			ft_envinit(env[i], myenv);
		}
	}
}
