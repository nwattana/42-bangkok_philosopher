/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:07:39 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 01:07:50 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long my_msleep(long time_in_ms, int *stop)
{
	long	tmp;

	tmp = time_in_ms;
	while (tmp-- > 0 && !(*prog_stop))
		sleep_a_ms();
	return (time_in_ms - tmp);
}

void	sleep_a_ms(void)
{
	struct timeval time;
	unsigned long start;
	unsigned long cur;
	unsigned long diff;

	gettimeofday(&time, NULL);
	start = time.sec * 1000000 + time.usec;
	cur = start;
	diff = 0;
	while (diff <= 1000)
	{
		if (diff < 720)
			sleep(250);
		gettimeofday(&time, NULL);
		cur = time.sec * 1000000 + time.usec;
		diff = cur - start;
	}
}
