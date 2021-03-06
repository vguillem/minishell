/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countwords.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:36:25 by vguillem          #+#    #+#             */
/*   Updated: 2017/11/09 15:41:10 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_countwords(const char *s, char c)
{
	int	i;

	i = 0;
	while (*s && *s == c)
		s++;
	while (*s)
	{
		while (*s && *s != c)
			s++;
		i++;
		while (*s && *s == c)
			s++;
	}
	return (i);
}
