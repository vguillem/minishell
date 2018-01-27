/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vguillem <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/06 08:13:08 by vguillem          #+#    #+#             */
/*   Updated: 2018/01/14 09:59:31 by vguillem         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H

# define MINISHELL_H

# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <sys/stat.h>
# include "libft/includes/libft.h"
# include "libft/gnl/get_next_line.h"
# include "libft/printf/libftprintf.h"

# define M_PATH_MAX 4096

int	g_son;

typedef struct	s_myenv
{
	char			*name;
	char			*data;
	struct s_myenv	*next;
}				t_myenv;
void			ft_mparse(t_myenv **env);
void			ft_mexe(char **paths, char **options, char **cenv);
void			ft_myenv(char **env, t_myenv **begin);
void			ft_mprintenv(t_myenv *myenv);
void			ft_freemyenv(t_myenv *myenv);
void			ft_msetenv(t_myenv **myenv, char **str, int *i);
void			ft_munsetenv(t_myenv **myenv, char **str, int *i);
void			ft_mcd(t_myenv *myenv, char **str);
void			ft_mecho(char **str);
void			ft_menv(t_myenv **myenv, char **str);
char			**ft_mpath(t_myenv *env);
int				ft_parsemyop(t_myenv **env, char **option);
char			**ft_menvtochar(t_myenv *myenv);
void			ft_mcpmyenv(t_myenv *myenv, t_myenv **tmpenv);
void			ft_mrecur(t_myenv **env, char **option, t_myenv **tmpenv);
void			ft_initsignal(void);
void			ft_mcdback(char **str, char *buf, int op, t_myenv *myenv);
void			ft_doubleslash(char *buf);
void			ft_mcdpurge(char *buf);
t_myenv			*ft_getenv(t_myenv *myenv, char *str);
int				ft_mcheckp(char *buf);

#endif
