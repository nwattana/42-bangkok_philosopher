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
	while (1)
	{
		printf("%d ms Philo %d is Think\n", dt->time, philo->id);
		pthread_mutex_lock(&philo->fork);
		printf("%d ms Philo %d is Taking Fork\n",dt->time, philo->id);
		pthread_mutex_lock(philo->o_fork);
		printf("%d ms Philo %d is Taking Other Fork\n",dt->time, philo->id);
		printf("\e[1;36mFrom %d my Remaining before EAT HP =%d\e[0m\n",philo->id, *(philo->my_live));
		printf("\e[1;31m%d ms Philo %d is Eating\e[0m\n",dt->time, philo->id);
		my_sleep(philo->table->philo_e);
		*(philo->my_live) = dt->philo_l;
		printf("\e[1;35mFrom %d my Remaining HP =%d\e[0m\n",philo->id, *(philo->my_live));
		pthread_mutex_unlock(&philo->fork);
		pthread_mutex_unlock(philo->o_fork);
		printf("%d ms Philo %d is Sleep\n",dt->time, philo->id);
		my_sleep(philo->table->philo_s);

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
				printf("\e[1;33m%d Philo Number %d DIE \e[0m\n", dt->time, i + 1);
		//		exit(0);
			}
			dt->pla[i] -= 1;
			i++;
		}
		my_sleep(1);
	}
}
