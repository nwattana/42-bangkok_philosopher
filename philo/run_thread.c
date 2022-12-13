/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 00:23:24 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/14 01:43:07 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    run_routine(t_prog *prog)
{
    int     index;
    int     i;
    t_philo *philo;

    i = 0;
    philo = prog->philo;
    prog->start = get_curtime();
    while (i < prog->cp)
    {
        philo[i].stime = prog->start;
        if (pthread_create(&(philo[i].p), NULL, &philo_rountine, &philo[i]) != 0)
        {
            putstr_fd("Pthread Create Error", 2);
            prog->stop = 1;
            return ;
        }
        i++;
    }
    pthread_create(&(prog->tb), NULL, &table_routine, prog);
    i = 0;
    while (i < prog->cp)
    {
        pthread_join(philo[i].p, NULL);
        index++;
    }
    pthread_join(prog->tb, NULL);
}
