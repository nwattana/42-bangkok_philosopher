/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:03:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 01:37:11 by nwattana         ###   ########.fr       */
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
	int					my_live;
	int					eat_times;
	pstate				pstate;
	pthread_t			ph;
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
	t_err		err
	int			philo_c;
	int			philo_l;
	int			philo_e;
	int			philo_s;
	int			philo_f;

	long		time_start;
	int			cur_time;
	int			dead_count;

	// stop = 0 -> no stop
	int			stop;
	pthread_t	table;
	t_philo		*philo;
}			t_dt;

/*
	collect Input phase
*/
int		collect_d(t_dt *dt, int ac, char **av);
t_err	is_validin(t_dt *ds, int c);

/*
	initail Phase
*/
void	setup_dinner_table(t_dt *dt);

/*
	start Routine
*/
void	invite_lst_add(t_philo **host, t_philo *guest);
t_philo	*philo_listed(int	i, t_dt *dt);

/*
	Utils
*/
int		my_sleep(long time_in_ms, int *stop); // 
void	sleep_a_ms(void); // 
int		get_curtime(t_dt *dt);


#endif
