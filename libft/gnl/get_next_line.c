/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/19 14:37:35 by vguillem          #+#    #+#             */
/*   Updated: 2017/12/02 11:23:22 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char		*ft_strnewcatn(char *s1, char *result, t_gnl **elem, int n)
{
	char	*tmp;

	if (!result)
	{
		result = ft_strnew(n);
		result = ft_strncpy(result, s1, n);
	}
	else
	{
		tmp = result;
		result = ft_strnew(ft_strlen(result) + n);
		result = ft_strcpy(result, tmp);
		result = ft_strncat(result, s1, n);
		ft_memdel((void **)&tmp);
	}
	if (s1[n + 1])
	{
		(*elem)->str = ft_strnew(ft_strlen(s1) - n - 1);
		(*elem)->str = ft_strcpy((*elem)->str, s1 + n + 1);
	}
	(*elem)->nbread = 1;
	return (result);
}

static char		*ft_strnewcat(char *s1, char *result, t_gnl **elem)
{
	int		n;
	char	*tmp;

	n = 0;
	while (s1[n] && s1[n] != '\n')
		n++;
	if (!(s1[n]))
	{
		if (!result)
			result = ft_strdup(s1);
		else
		{
			tmp = result;
			result = ft_strnew(ft_strlen(result) + ft_strlen((s1)));
			result = ft_strcpy(result, tmp);
			result = ft_strcat(result, s1);
			ft_memdel((void **)&tmp);
		}
	}
	else
		result = ft_strnewcatn(s1, result, elem, n);
	return (result);
}

static int		ft_gnlread(int fd, t_gnl **elem, char **result)
{
	int		ret;
	char	tmp[BUFF_SIZE + 1];

	if ((*elem)->str)
	{
		if (!((*elem)->str[0]))
			ft_memdel((void **)&(*elem)->str);
		else
		{
			*result = ft_strdup((*elem)->str);
			ft_memdel((void **)&(*elem)->str);
		}
	}
	(*elem)->nbread = 0;
	while ((ret = read(fd, tmp, BUFF_SIZE)))
	{
		if (ret == -1)
			return (0);
		tmp[ret] = '\0';
		*result = ft_strnewcat(tmp, *result, elem);
		if ((*elem)->nbread == 1)
			return (1);
	}
	return (1);
}

static t_gnl	*ft_initlst(int fd, t_gnl **lst)
{
	t_gnl	*tmp;
	t_gnl	*tmp2;

	tmp = *lst;
	tmp2 = NULL;
	while (tmp)
	{
		if (tmp->fd == fd)
			return (tmp);
		tmp2 = tmp;
		tmp = tmp->next;
	}
	tmp = (t_gnl *)ft_memalloc(sizeof(t_gnl));
	tmp->fd = fd;
	tmp->nbread = 0;
	tmp->next = NULL;
	tmp->str = NULL;
	tmp->endfile = 0;
	if (tmp2)
		tmp2->next = tmp;
	else
		*lst = tmp;
	return (tmp);
}

int				get_next_line(const int fd, char **line)
{
	static t_gnl	*lst;
	t_gnl			*t;
	char			*result;
	int				i;

	i = 0;
	if (fd < 0 || !(line) || BUFF_SIZE < 1)
		return (-1);
	*line = NULL;
	t = ft_initlst(fd, &lst);
	while (t->str && t->str[i] && t->str[i] != '\n')
		i++;
	if (t->str && t->str[i] == '\n')
	{
		result = t->str;
		*line = ft_strncpy(ft_strnew(i), t->str, i);
		t->str = ft_strcpy(ft_strnew(ft_strlen(t->str) - i), result + i + 1);
		ft_memdel((void **)&result);
		return (1);
	}
	if (!(ft_gnlread(fd, &t, line)))
		return (-1);
	if (!(*line) || t->endfile == 1)
		return ((t->endfile = 1) - 1);
	return (1);
}
