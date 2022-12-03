/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_dinner.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 12:10:07 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 01:07:35 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	philo->my_live = dt->philo_l;
	pthread_mutex_init(&(philo->fork), NULL);
	philo->table = dt;
	philo->eat_times = dt->philo_f;
	philo->pstate = READY;
	return (philo);
}

