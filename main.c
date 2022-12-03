/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:16:09 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 01:20:50 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dump.h"

int	main(int ac, char **av)
{
	t_dt	dt;

	if (ac < 5 || ac > 6)
		return (1);
	dt.err = 0;
	collect_d(&dt, ac, av);
	if (!dt.err)
	{
		init_tb(&dt);
		inti_philo(&dt);

	}
	return (0);
}

void	init_tb(t_dt *dt)
{
	dt->dead_count = 0;
	dt->stop = 0;
}

void	init_philo(t_dt *dt)
{
	t_philo *philo;
	int		i;

	while (i < dt->philo)
	{
		philo = philo_listed(i + 1, dt);
		invite_lst_add(&(dt->philo), philo);
		i++;
	}
}
