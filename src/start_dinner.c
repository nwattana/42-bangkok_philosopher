/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:10:07 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 14:12:56 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_dinner(t_dt *dt)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = dt->philo;

	pthread_create(&(dt->table), NULL, &tbr, dt);
	i = 0;
	while (i < dt->philo_c)
	{
		if (i % 2 == 0)
		{
			pthread_create(&(philo->p), NULL, &routine, philo);
		}
		philo = philo->n_philo;
		i++;
		usleep(1);
	}

	i = 0;
	while (i < dt->philo_c)
	{
		if (i % 2)
		{
			pthread_create(&(philo->p), NULL, &routine, philo);
		}
		philo = philo->n_philo;
		i++;
		usleep(1);
	}
	pthread_join(dt->table,NULL);
	i = 0;
	while (i < dt->philo_c)
	{
		pthread_join(philo->p,NULL);
		philo = philo->n_philo;
		i++;
	}
}

void	invite_guest(t_dt *dt)
{
	int	i;
	t_philo *tmp;

	i = 1;
	dt->philo = NULL;
	while (i <= dt->philo_c)
	{

		tmp = philo_listed(i, dt);
		if (!tmp)
		{
			dt->err = MALLOC_FAIL;
			return ;
		}
		invite_lst_add(&(dt->philo), tmp);
		i++;
	}
}

void	invite_lst_add(t_philo **host, t_philo *guest)
{
	t_philo *tmp;

	if (!host)
		return ;
	if (!(*host))
	{
		*host = guest;
		guest->n_philo = guest;
		guest->o_fork = &(guest->fork);
		return ;
	}
	tmp = *host;
	while (tmp->n_philo->id > tmp->id)
		tmp = tmp->n_philo;
	guest->o_fork = tmp->o_fork;
	tmp->o_fork = &(guest->fork);
	tmp->n_philo = guest;
	guest->n_philo = *host;
}

t_philo	*philo_listed(int i, t_dt *dt)
{
	t_philo		*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = i;
	philo->my_live = &(dt->pla[i - 1]);
	pthread_mutex_init(&(philo->fork), NULL);
	philo->table = dt;
	return (philo);
}

int	my_sleep(int time_in_ms)
{
	unsigned long pre;
	unsigned long cur;
	unsigned long dif;
	struct timeval time;

	gettimeofday(&time, NULL);
	pre = time.tv_sec * 10000000 + time.tv_usec;
	while (time_in_ms)
	{
		gettimeofday(&time, NULL);
		cur	 = time.tv_sec * 10000000 + time.tv_usec;
		dif = cur - pre;
		if (dif > 1000)
		{
			time_in_ms--;
			pre = cur;
		}
	}
	return (0);
}

int	my_usleep(int time_in_us)
{
	unsigned long pre;
	unsigned long cur;
	unsigned long dif;
	struct timeval time;

	gettimeofday(&time, NULL);
	pre = time.tv_sec * 10000000 + time.tv_usec;
	while (time_in_us)
	{
		gettimeofday(&time, NULL);
		cur	 = time.tv_sec * 10000000 + time.tv_usec;
		dif = cur - pre;
		if (dif > 1)
		{
			time_in_us--;
			pre = cur;
		}
	}
	return (0);
}
