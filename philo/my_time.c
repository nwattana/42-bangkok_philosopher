/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_time.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 23:03:07 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/14 01:49:01 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    my_sleep(long ms, t_prog *prog)
{
    long    start;

    start = get_curtime();
    while (prog->stop && (get_curtime() - start) < ms)
	{
		if	get_curtime() - start 
		usleep(200);
	}
}

void    my_usleep(int us_time)
{
    struct timeval  time;
    long            cur;
    long            start;

    gettimeofday(&time, NULL);
    start = time.tv_sec*1000000 + time.tv_usec;
    cur = start;
    while (cur - start > us_time)
    {
        gettimeofday(&time, NULL);
        cur = time.tv_sec * 1000000 + time.tv_usec;
    }
}

long    get_curtime(void)
{
    struct timeval time;

    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000 + (time.tv_usec / 1000));
}

int    actiontime(long time)
{
    return (get_curtime() - time);
}
