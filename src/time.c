/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/04 01:11:34 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/04 03:28:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	get_curtime(t_dt *dt)
{
	struct timeval time;
	long cur_time;

	gettimeofday(&time,NULL);
	cur_time = time.sec * 1000000 + time.usec;
	return (cur_time - dt->time_start);
}
