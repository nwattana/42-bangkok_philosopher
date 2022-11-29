/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 12:16:09 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 12:40:23 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dump.h"

int	main(int ac, char **av)
{
	t_dt	dt;

	dt.err = 0;
	collect_d(&dt, ac, av);
	if (!dt.err)
	{
		setup_dinner_table(&dt);
		invite_guest(&dt);
		start_dinner(&dt);
	}
	else if (dt.err == NOT_ACCEPT_INPUT)
		printf("Check You \e[1;31mINPUT\e[0m Please!!\n");
	else
		printf("error = %d\n", dt.err);
	return (0);
}

