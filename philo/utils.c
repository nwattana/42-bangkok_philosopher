/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:47:48 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/13 19:47:56 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    putstr_fd(char *s, int fd)
{
    int     i;

    i = 0;
    if (fd < 1)
        return ;
    while (s[i])
        i++;
    write(fd, s, i);
}

int get_index(int i, int size)
{
    int edge;

    if (size <= 3)
        return (i);
    edge = size / 2 + size % 2;
    return ((2 * i) * (edge > i) + (2 * (i - edge) + 1 ) * (i >= edge));
}

void    ft_exit(t_prog *prog)
{
    if (!prog)
        return ;
    if (prog->philo)
        free(prog->philo);
    prog->philo = NULL;
}