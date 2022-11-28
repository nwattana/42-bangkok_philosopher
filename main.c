/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:16:09 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 02:09:09 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dump.h"

int	main(int ac, char **av)
{
	t_dt	dt;

	collect_d(&dt, ac, av);
	if (!dt.err)
	{
		set_up_dinner_table(&dt);
	}
	else if (dt.err == NOT_ACCEPT_INPUT)
		printf("Check You \e[1;31mINPUT\e[0m Please!!\n");
	else
		printf("error = %d\n", dt.err);
	return (0);
}


void	set_updinner_table(t_dt *dt)
{
	int		i;

	i = 0;
	if (dt->error)
		return ;
	dt->pla = malloc(sizeof(int) * dt->philo_c);
	if (!dt->pla)
		return ;

	/*
		Co
	*/
	while (i < dt->philo_c)
	{
		dt->pla[i] = philo_l;
		i++;
	}
}

