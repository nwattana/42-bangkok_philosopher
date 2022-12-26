/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_param.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 11:45:33 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/26 11:53:26 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	isvalid_param(t_prog *prog)
{
	if (prog->cp > 200 || prog->cp <= 0)
		putstr_fd("INVALID PHILO AMOUNT", 2);
	else if (prog->dp < 60 || prog->ep < 60 || prog->sp < 60)
		putstr_fd("INVALID PHILO TIME", 2);
	else if (prog->iscount && prog->cep == 0)
		prog->err = 1;
	else
		return (0);
	return (1);
}
