/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dump.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 17:03:01 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/20 17:11:43 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	dump_dt(t_dt *dt)
{
	printf("Philo \t\t\t%d ea\n", dt->philo_c);
	printf("time before die\t\t%d ms\n", dt->philo_l);
	printf("time to eat\t\t%d ms\n", dt->philo_e);
	printf("time to sleep\t\t%d ms\n", dt->philo_s);
	printf("How many meal:\t\t%d meals\n", dt->philo_f);
}
