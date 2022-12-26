/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:50:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/26 05:57:04 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include "str_const.h"

typedef struct s_prog	t_prog;

typedef enum e_pstate
{
	P_READY,
	P_INIT,
	P_ROUNTINE,
	P_DONE
}						t_pstate;

typedef struct s_philo
{
	int					id;
	pthread_t			p;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	t_prog				*prog;
	long				stime;
	int					pstate;
	int					ec;
	long				last_eat;
}						t_philo;

struct s_prog
{
	t_philo		*philo;
	int			cp;
	int			dp;
	int			ep;
	int			sp;
	int			cep;
	int			err;
	pthread_t	tb;
	int			start;
	int			stop;
	int			iscount;
	int			full;
};

void	get_info(t_prog *prog, int ac, char **av);
void	init_prog(t_prog *prog);
int		isstrnum(const char *s);
int		atoint(const char *s);
void	run_routine(t_prog *prog);
void	create_philo(t_prog *prog);
void	philo_init_mutex(t_philo *philo, t_prog *prog);
void	*philo_rountine(void *arg);
void	*table_routine(void *arg);
void	run_routine(t_prog *prog);
void	ft_exit(t_prog *prog);
int		get_index(int i, int size);
long	get_curtime(void);
void	my_usleep(int us_time);
void	my_sleep(long ms, t_prog *prog);
int		actiontime(long time);
void	pprog(t_prog *prog);
void	putstr_fd(char *str, int fd);
#endif
