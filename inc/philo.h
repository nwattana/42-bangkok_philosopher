/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 01:03:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/20 17:06:06 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include "tn_numeric.h"

typedef	struct	s_philo
{
	char	state;
	pthread_t	tid;
}			t_philo;

/*
dt ? dinner_table
philo_c - count
philo_l - live
philo_e - eat
philo_s - sleep
philo_f - full
	
*/
typedef struct s_dt
{
	t_err	err;
	int		philo_c;
	int		philo_l;
	int		philo_e;
	int		philo_s;
	int		philo_f;
}			t_dt;

int	collect_d(t_dt *dt, int ac, char **av);

#endif
