/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 09:16:45 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:58:42 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_handler_sigint(int signal)
{
	if (g_son == 0 && signal == SIGINT)
		ft_putstr("\n$>");
}

void	ft_handler_basic(int signal)
{
	kill(0, signal);
}

void	ft_initsignal(void)
{
	signal(SIGINT, ft_handler_sigint);
}
