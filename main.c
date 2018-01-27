/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:44 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:21:28 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_mav(t_myenv *myenv, int ac, char **av)
{
	char	**option;
	int		i;

	i = 1;
	while (ac-- > 1)
	{
		option = ft_strsplit(av[i], ' ');
		if (option)
		{
			ft_mrecur(&myenv, option, &myenv);
			ft_strdeltab(&option);
		}
		i++;
	}
}

int		main(int ac, char **av, char **env)
{
	t_myenv	*myenv;
	t_myenv	*pwd;

	ft_initsignal();
	g_son = 0;
	myenv = NULL;
	ft_myenv(env, &myenv);
	pwd = myenv;
	while (pwd && ft_strcmp("PWD", pwd->name) != 0)
		pwd = pwd->next;
	if (ac > 1)
		ft_mav(myenv, ac, av);
	while (1)
	{
		ft_putstr("$>");
		ft_mparse(&myenv);
	}
}
