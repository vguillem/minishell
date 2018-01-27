/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mcdutil.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 08:02:10 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:54:42 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		ft_mcheckp(char *buf)
{
	struct stat	st;

	lstat(buf, &st);
	if (access(buf, F_OK) == -1)
		ft_dprintf(2, "cd: no such file or directory: %s\n", buf);
	else if (access(buf, X_OK) == -1)
	{
		if (S_ISDIR(st.st_mode) || S_ISLNK(st.st_mode))
			ft_dprintf(2, "cd: permission denied: %s\n", buf);
		else
			ft_dprintf(2, "cd: not a directory: %s\n", buf);
	}
	else if (!S_ISDIR(st.st_mode) && !S_ISLNK(st.st_mode))
		ft_dprintf(2, "cd: not a directory: %s\n", buf);
	else
		return (1);
	return (0);
}

void	ft_mcdback(char **str, char *buf, int op, t_myenv *myenv)
{
	t_myenv		*oldpwd;

	oldpwd = myenv;
	if (str[op + 1])
		ft_dprintf(2, "minishell: cd: too many arguments");
	else
	{
		while (oldpwd && ft_strcmp("OLDPWD", oldpwd->name) != 0)
			oldpwd = oldpwd->next;
		if (oldpwd)
			ft_strcpy(buf, oldpwd->data);
		else
			return ;
	}
}

void	ft_mcdpurgep(char *buf, int i, char *tmp)
{
	if (!buf[i + 1])
		buf[i] = 0;
	else if (buf[i + 1] == '/')
	{
		tmp = ft_strdup(buf + i + 2);
		buf[i] = 0;
		if (tmp)
		{
			ft_strcat(buf, tmp);
			ft_strdel(&tmp);
		}
	}
}

void	ft_mcdpurgepp(char *buf, int i, int j, char *tmp)
{
	j = i - 2;
	while (j >= 0 && buf[j] != '/')
		j--;
	if (i == 0 || j <= 0)
	{
		if (!buf[i + 2])
		{
			buf[0] = '/';
			buf[1] = 0;
		}
		else
			ft_strcpy(buf, buf + i + 2);
	}
	else
	{
		tmp = ft_strdup(buf + i + 3);
		ft_bzero(buf + j + 1, M_PATH_MAX - j - 1);
		if (tmp)
		{
			ft_strcat(buf, tmp);
			ft_strdel(&tmp);
		}
	}
}

void	ft_mcdpurge(char *buf)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	j = 0;
	tmp = NULL;
	while (buf[i])
	{
		if (buf[i] == '.' && (i == 0 || buf[i - 1] == '/'))
		{
			if (!buf[i + 1] || buf[i + 1] == '/')
				ft_mcdpurgep(buf, i, tmp);
			else if (buf[i + 1] == '.' && (buf[i + 2] == '/' || !buf[i + 2]))
				ft_mcdpurgepp(buf, i, j, tmp);
			i = -1;
		}
		i++;
	}
	ft_doubleslash(buf);
}
