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
        printf("%d",ac);
        return (1);
    }
    get_info(&prog,ac,av);
    pprog(&prog);
}

