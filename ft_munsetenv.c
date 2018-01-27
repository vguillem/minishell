/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_munsetenv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 09:17:55 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/27 08:15:31 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mdelenv(t_myenv *env)
{
	if (env)
	{
		if (env->data)
			ft_strdel(&env->data);
		if (env->name)
			ft_strdel(&env->name);
		ft_memdel((void **)&env);
	}
}

void	ft_munsetenv(t_myenv **myenv, char **str, int *i)
{
	t_myenv	*tenv;
	t_myenv	*tmp;

	tenv = *myenv;
	tmp = NULL;
	if (!str[*i])
		return ;
	while (tenv && tenv->name && ft_strcmp(tenv->name, str[*i]) != 0)
	{
		tmp = tenv;
		tenv = tenv->next;
	}
	if (tenv && !tmp)
		*myenv = tenv->next;
	else if (tenv && tmp)
		tmp->next = tenv->next;
	ft_mdelenv(tenv);
	(*i)++;
}
