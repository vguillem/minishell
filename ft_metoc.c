/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_metoc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 09:16:28 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:16:40 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_initc(char *name, char *data)
{
	char	*path;

	path = ft_strnew(ft_strlen(name) + ft_strlen(data) + 1);
	ft_strcpy(path, name);
	ft_strcat(path, "=");
	ft_strcat(path, data);
	return (path);
}

char	**ft_menvtochar(t_myenv *myenv)
{
	char	**result;
	int		i;
	t_myenv	*tmp;

	i = 0;
	tmp = myenv;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	result = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (myenv)
	{
		result[i++] = ft_initc(myenv->name, myenv->data);
		myenv = myenv->next;
	}
	if (*result)
		result[i] = NULL;
	return (result);
}
