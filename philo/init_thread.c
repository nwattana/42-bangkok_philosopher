/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_thread.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 20:28:50 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/13 20:29:02 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    create_philo(t_prog *prog)
{
    int     index;
    t_philo *philo;

    index = 0;
    philo = malloc(sizeof(t_philo) * prog->cp + 1);
    if (!philo)
    {
        prog->err = 1;
        putstr_fd("Malloc Failed",2);
        return ;
    }
    philo_init_mutex(philo, prog);
    while (index < prog->cp)
    {
        philo[index].id = index + 1;
        philo[index].prog = prog;
        philo[index].pstate = P_INIT;
        index++;
    }
    prog->philo = philo;
}

void    philo_init_mutex(t_philo *philo, t_prog *prog)
{
    int     index;

    index = 0;
    while (index < prog->cp)
    {
        if (pthread_mutex_init(&(philo[index].r_fork), NULL) != 0)
        {
            putstr_fd("Mutex Init Error\n",2);
            prog->err = 1;
            return ;
        }
        index++;
    }
    index = 0;
    while (index < prog->cp)
    {
        if (index + 1 < prog->cp)
            philo[index].l_fork = &(philo[index + 1].r_fork);
        else
            philo[index].l_fork = &(philo[0].r_fork);
        index++;
    }
}

