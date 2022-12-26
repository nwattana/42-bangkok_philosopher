/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:47:45 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/26 11:37:02 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	to_print(char *str, int act, int id, int stop);

int	main(int ac, char **av)
{
	t_prog	prog;

	init_prog(&prog);
	if (ac < 5 || ac > 6)
	{
		putstr_fd("Invalid Input Amount\n", 2);
		return (1);
	}
	get_info(&prog, ac, av);
	if (!prog.err)
	{
		create_philo(&prog);
		run_routine(&prog);
	}
	return (0);
}

void	*philo_rountine(void *arg)
{
	t_philo	*ph;

	ph = (t_philo *)arg;
	if (ph->id % 2 == 0)
		usleep(50);
	while (ph->prog->stop)
	{
		pthread_mutex_lock(&ph->r_fork);
		to_print(P_TAKE, actiontime(ph->stime), ph->id, ph->prog->stop);
		pthread_mutex_lock(ph->l_fork);
		to_print(P_TAKE, actiontime(ph->stime), ph->id, ph->prog->stop);
		to_print(P_EAT, actiontime(ph->stime), ph->id, ph->prog->stop);
		ph->last_eat = actiontime(ph->stime);
		my_sleep(ph->prog->ep, ph->prog);
		ph->ec++;
		pthread_mutex_unlock(ph->l_fork);
		pthread_mutex_unlock(&ph->r_fork);
		if (ph->prog->iscount && ph->ec >= ph->prog->cep)
			break ;
		to_print(P_SLEEP, actiontime(ph->stime), ph->id, ph->prog->stop);
		my_sleep(ph->prog->sp, ph->prog);
		to_print(P_THINK, actiontime(ph->stime), ph->id, ph->prog->stop);
	}
	ph->pstate = P_DONE;
	return (NULL);
}

void	to_print(char *str, int act, int id, int stop)
{
	if (!stop)
		return ;
	printf(str, act, id);
}

void	*table_routine(void *arg)
{
	t_prog	*prog;
	int		index;

	prog = (t_prog *)arg;
	while (prog->stop && prog->full < prog->cp)
	{
		index = 0;
		prog->full = 0;
		while (prog->stop && index < prog->cp)
		{
			if (prog->philo[index].pstate == P_DONE)
				prog->full++;
			if (actiontime(prog->start) - \
				prog->philo[index].last_eat > prog->dp)
			{
				printf(P_DIED, actiontime(prog->start), index + 1);
				prog->stop = 0;
			}
			index++;
		}
	}
	usleep(100);
	ft_exit(prog);
	return (NULL);
}
