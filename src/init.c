/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 02:25:49 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 13:42:37 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void		hp_bar(t_dt *dt);
void	setup_dinner_table(t_dt *dt)
{
	int		i;

	i = 0;
	if (dt->err)
		return ;
	hp_bar(dt);
	dt->time = 0;
}

static void		hp_bar(t_dt *dt)
{
	int	i;
	int	*tmp;

	i = 0;
	if (!dt)
		return ;
	tmp = malloc(sizeof(int) * dt->philo_c);
	if (!tmp)
	{
		dt->err = MALLOC_FAIL;
		return ;
	}
	while (i < dt->philo_c)
	{
		tmp[i] = dt->philo_l;
		i++;
	}
	dt->pla = tmp;
}
