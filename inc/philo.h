/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:08:03 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 02:09:14 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:03:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 01:52:23 by nwattana         ###   ########.fr       */
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


typedef	struct	s_philo
{
	int		name;
	int		*my_live;
}			t_philo;

/*
dt ? dinner_table
philo_c - count
philo_l - live
philo_e - eat
philo_s - sleep
philo_f - full -> eat times
pla - philo live array Collect Philo Live
table -> thread which manipulated the other thread
*/
typedef struct s_dt
{
	t_err	err;
	int		philo_c;
	int		philo_l;
	int		philo_e;
	int		philo_s;
	int		philo_f;

	int		time;
	int		*pla;
	pthread_t	table;
	t_philo	*philo;
}			t_dt;


/*
	collect input phase
*/
int		collect_d(t_dt *dt, int ac, char **av);
t_err	is_validin(t_dt *ds, int c);

/*
	initail phase
*/
void	set_up_dinner_table(t_dt *dt);

/*
	start dinning
*/

#endif
