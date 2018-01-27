/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mecho.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:12:14 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:11:39 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_mparseecho(char **str, int *n)
{
	int		i;

	i = 1;
	while (str[i] && str[i][0] == '-')
	{
		if (ft_strcmp(str[i], "-") == 0)
		{
			i++;
			break ;
		}
		else if (str[i] && ft_strcmp(str[i], "-n") == 0)
		{
			*n = 1;
			i++;
		}
		else
			break ;
	}
	return (i);
}

int		ft_mput(char str)
{
	if (str == '\\')
		ft_putchar('\\');
	else if (str == 'a')
		ft_putchar('\a');
	else if (str == 'b')
		ft_putchar('\b');
	else if (str == 'n')
		ft_putchar('\n');
	else if (str == 'f')
		ft_putchar('\f');
	else if (str == 'r')
		ft_putchar('\r');
	else if (str == 't')
		ft_putchar('\t');
	else if (str == 'v')
		ft_putchar('\v');
	else
		ft_putchar(str);
	return (1);
}

void	ft_mecho(char **str)
{
	int		n;
	int		i;
	int		j;

	n = 0;
	i = ft_mparseecho(str, &n);
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] == '\\')
			{
				j++;
				if (str[i][j])
					j += ft_mput(str[i][j]);
			}
			else
				ft_putchar(str[i][j++]);
		}
		if (str[++i])
			ft_putchar(' ');
	}
	if (n == 0)
		ft_putchar('\n');
}
