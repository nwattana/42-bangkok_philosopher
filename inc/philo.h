/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:03:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 13:29:39 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <string.h>
# include "tn_numeric.h"

# define PHILO_LIMIT 200
# define ACTION_TIME_LIMIT 60


typedef struct s_dt t_dt;
/*
	id -> to naming Philo
	*my_live -> point to live in table
	p-> thread
	*fork -> Philo's Fork
	o_fork -> for point to the other fork
*/
typedef	struct	s_philo
{
	int					id;
	int					*my_live;
	pthread_t			p;
	pthread_mutex_t		fork;
	pthread_mutex_t		*o_fork;
	struct s_philo		*n_philo;
	t_dt	*table;
}			t_philo;

/*
	dt ? dinner_table
	philo_c - count
	philo_l - live
	philo_e - eat
	philo_s - sleep
	philo_f - full -> eat times
	time -> time in ms count from start
	pla - philo live array Collect Philo Live
	table -> thread which manipulated the other thread
*/
typedef struct s_dt
{
	t_err		err;
	int			philo_c;
	int			philo_l;
	int			philo_e;
	int			philo_s;
	int			philo_f;

	int			time;
	int			*pla;
	pthread_t	table;
	t_philo		*philo;
}			t_dt;


/*
	collect input phase
*/
int		collect_d(t_dt *dt, int ac, char **av);
t_err	is_validin(t_dt *ds, int c);

/*
	initail phase
*/
void	setup_dinner_table(t_dt *dt);

/*
	start dinning
*/
void	start_dinner(t_dt *dt);
void	*routine(void *arg);
void	invite_guest(t_dt *dt);
void	invite_lst_add(t_philo **host, t_philo *guest);
t_philo	*philo_listed(int	i, t_dt *dt);
void	*tbr(void	*arg);
#endif
