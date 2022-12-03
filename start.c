/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:21:12 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 03:28:41 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_dt *dt)
{
	int	i;
	struct timeval time;
	t_philo *philo;

	i = 0;
	if (dt->err)
		return ;
	philo = dt->philo;
	gettimeofday(&time, NULL);
	dt->time_start = time.sec * 1000000 + time.usec;
	while (i < dt->philo_c)
	{
		if (i % 2 == 0)
			pthread_creat(&(philo->ph), NULL, &prt, (void *)philo);
		philo = philo->next;
		i++;
	}
}

void	*prt(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	philo->pstate = WAITING
	while (!owner->dt->stop)
	{
		pthread_mutex_lock(&(philo->fork));
		pthread_mutex_lock(philo->o_fork);
		philo->pstate = EATING
		philo_eat(philo);
		philo->pstate = SLEEP;
		pthread_mutex_unlock(philo->o_fork);
		pthread_mutex_unlock(&(philo->fork));
		philo->pstate = WAITING
	}
}


void	*dinner_table_routine(void *arg)
{
	t_dt *dt;

	dt = (t_dt *)arg;
	while (!dt->stop)
	{
		
	}
}
