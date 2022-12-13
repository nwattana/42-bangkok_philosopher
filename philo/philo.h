/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 01:50:10 by nwattana          #+#    #+#             */
/*   Updated: 2022/12/12 02:03:41 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <sys/time.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_prog	t_prog;

typedef enum e_pstate
{
	P_READY,
	P_ROUNTINE,
	P_DONE
}						t_pstate;

typedef struct s_philo
{
	pthread_t			p;
	pthread_mutex_t		r_fork;
	pthread_mutex_t		*l_fork;
	t_prog				*prog;
	int					pstate;
	int					start_time;

}						t_philo;

struct s_prog
{
	int					cp;
	int					dp;
	int					ep;
	int					sp;
	int					cep;
	int					err;
	pthread_t			ti;
	int					stop;
	int					iscount;

};

/*	input phase */



/*	Debug program */
void	pprog(t_prog *prog);
void    get_info(t_prog *prog, int ac, char **av);
void    init_prog(t_prog *prog);
int     isstrnum(const char *s);
int     atoint(const char *s);
#endif
