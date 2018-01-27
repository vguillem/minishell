/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_menv.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 10:34:27 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/27 08:13:52 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_menvbadop(char c)
{
	ft_dprintf(2, "env: illegal option -- %c\n", c);
	ft_dprintf(2, "usage: env [-i] [-u name] [name=value]\n");
	ft_dprintf(2, "[utility [argument ...]]\n");
}

int		ft_menvop(char **str, t_myenv **tmpenv, int *i)
{
	while (str[*i])
	{
		if ((ft_strcmp("-", str[*i]) == 0) ||
				(ft_strncmp("-i", str[*i], 2) == 0))
		{
			ft_freemyenv(*tmpenv);
			*tmpenv = NULL;
			(*i)++;
		}
		else if (ft_strcmp("-u", str[*i]) == 0)
		{
			(*i)++;
			if (str[*i])
				ft_munsetenv(tmpenv, str, i);
		}
		else if (ft_strncmp("-", str[*i], 1) == 0)
		{
			ft_menvbadop(str[*i][1]);
			return (3);
		}
		else
			return (0);
	}
	return (0);
}

void	ft_menv(t_myenv **myenv, char **str)
{
	int		op;
	int		i;
	t_myenv	*tmpenv;

	ft_mcpmyenv(*myenv, &tmpenv);
	i = 1;
	op = 0;
	op = ft_menvop(str, &tmpenv, &i);
	if (op == 0)
	{
		while (str[i] && ft_strchr(str[i], '='))
			ft_msetenv(&tmpenv, str, &i);
		if (str[i])
			ft_mrecur(myenv, str + i, &tmpenv);
		else
			ft_mprintenv(tmpenv);
	}
	ft_freemyenv(tmpenv);
}
