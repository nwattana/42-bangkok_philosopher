/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 19:37:46 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/13 19:37:48 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    get_info(t_prog *prog, int ac, char **av)
{
    int     index;

    index = 1;
    while (index < ac)
    {
        if (isstrnum(av[index]) == 0)
            prog->err = 1;
        index++;    
    }
    if (!prog->err)
    {
        prog->cp = atoint(av[1]);
        prog->dp = atoint(av[2]);
        prog->ep = atoint(av[3]);
        prog->sp = atoint(av[4]);
        if (ac == 6)
        {
            prog->cep = atoint(av[5]);
            prog->iscount = 1;
        }    
    }
}

void    init_prog(t_prog *prog)
{
    prog->philo = NULL;
    prog->cp = 0;
    prog->dp = 0;
    prog->ep = 0;
    prog->sp = 0;
    prog->cep = 0;
    prog->err = 0;
    prog->stop = 1;
    prog->iscount = 0;
}

int     isstrnum(const char *s)
{
    if (s == NULL)
        return (0);
    while(*s)
    {
        if (*s < '0' || *s > '9')
            return (0);
        s++;
    }
    return (1);
}

int     atoint(const char *s)
{
    long    num;

    num = 0;
    while (*s)
    {
        num *= 10;
        num += *s - '0';
        s++;
    }
    return (num);
}

void    pprog(t_prog *prog)
{
    printf("count = %d\n",prog->cp);
    printf("dead = %d\n",prog->dp);
    printf("eat time = %d\n",prog->ep);
    printf("sleep time = %d\n",prog->sp);
    printf("count = %d\n",prog->cep);
    printf("err = %d\n",prog->err);
    printf("stop = %d\n",prog->stop);
    printf("iscount %d\n",prog->iscount);
}
