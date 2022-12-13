/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:47:45 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/12 01:47:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int main(int ac, char **av)
{
    t_prog  prog;

    init_prog(&prog);
    if (ac < 5 || ac > 6)
    {
        putstr_fd("Invalid Input Amount\n",2);
        return (1);
    }
    get_info(&prog,ac,av);
    create_philo(&prog);

    run_routine(&prog);
}


void    *philo_rountine(void *arg)
{
    t_philo *ph;
    int     id;
    long    start;

    ph = (t_philo *)arg;
    id = ph->id;
    if(id % 2 == 0)
        my_usleep(20);
    start = ph->prog->start;
    printf("%ld\n",start);
    while (ph->prog->stop)
    {
        
        pthread_mutex_lock(&ph->r_fork);
        if (ph->prog->stop)
            printf("%d ms %d has taken fork\n", actiontime(ph->stime), id);
        pthread_mutex_lock(ph->l_fork);
        if (ph->prog->stop)
            printf("%d ms %d has taken fork\n", actiontime(ph->stime), id);
        if (ph->prog->stop)
            printf("%d ms %d is Eating\n", actiontime(ph->stime), id);
        ph->last_eat = actiontime(ph->stime);
        my_sleep(ph->prog->ep, ph->prog);
        ph->ec++;
        pthread_mutex_unlock(ph->l_fork);
        pthread_mutex_unlock(&ph->r_fork);
        if (ph->prog->iscount && ph->ec > ph->prog->cep)
            break ;
        if (ph->prog->stop)
            printf("%d ms %d is Sleeping\n", actiontime(ph->stime), id);
        my_sleep(ph->prog->sp, ph->prog);
    }
    ph->pstate = P_DONE;
    return (NULL);
}

void    *table_routine(void *arg)
{
    t_prog *prog;
    int     index;
    prog = (t_prog *)arg;
    while (prog->stop)
    {
        index = 0;
        while (index < prog->cp)
        {
            if (actiontime(prog->start) - prog->philo[index].last_eat > prog->dp)
            {
                printf("%ld\n",get_curtime() - prog->philo[index].last_eat);
                printf("at %d ms %d died %d\n",actiontime(prog->start),index + 1, prog->dp);
                prog->stop = 0;
            }
            my_usleep(10);
            index++;
        }
    }
    usleep(100);
    ft_exit(prog);
    return (NULL);
}

