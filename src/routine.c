/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:14:18 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 14:12:58 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo	*philo;
	t_dt *dt;

	philo = (t_philo *)arg;
	dt = philo->table;
	;
	while (1)
	{
		printf("%d ms Philo %d is Think\n", dt->time, philo->id);
		pthread_mutex_lock(&philo->fork);
		printf("%d ms Philo %d is Taking Fork\n",dt->time, philo->id);
		pthread_mutex_lock(philo->o_fork);
		printf("%d ms Philo %d is Taking Other Fork\n",dt->time, philo->id);
		printf("%d ms Philo %d is Eating\n",dt->time, philo->id);
		usleep(philo->table->philo_e * 1000);
		*(philo->my_live) = dt->philo_l;
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->o_fork);
		printf("%d ms Philo %d is Sleep\n",dt->time, philo->id);
		usleep(philo->table->philo_s * 1000);

	}
}

void	*tbr(void	*arg)
{
	t_dt *dt;
	int		i;

	dt = (t_dt*)arg;
	while (1)
	{
		i = 0;
		dt->time++;
		while (i < dt->philo_c)
		{
			if (dt->pla[i] <= 0)
			{
				printf("\e[1;31m%d Philo Number %d DIE \e[0m\n", dt->time, i + 1);
				exit(0);

			}
			dt->pla[i] -= 1;
			i++;
		}
		usleep(1000);
	}
}
