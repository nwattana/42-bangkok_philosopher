/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:13:22 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 12:41:56 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"
#include "dump.h"

static int		get_val(const char *s, t_dt *dt);
static int		m_strlen(const char *s);
static int		ft_atoi_m(const char *s);
static int		isstrnum(const char *str);

int	collect_d(t_dt *dt, int ac, char **av)
{
	int		i;

	if (ac < 4 || ac > 7)
		return (INVALID_INPUT_AMOUNT);
	i = 1;
	dt->philo_f = -1;
	dt->philo_c = get_val(av[i++], dt);
	dt->philo_l = get_val(av[i++], dt);
	dt->philo_e = get_val(av[i++], dt);
	dt->philo_s = get_val(av[i++], dt);
	if (ac == 6)
		dt->philo_f = get_val(av[i], dt);
	if (!(dt->err))
		dt->err = is_validin(dt, ac);
	return (dt->err);
}

t_err	is_validin(t_dt *dt, int ac)
{
	if (dt->philo_c > 199 || dt->philo_l < 60 || dt->philo_e < 60 \
			|| dt->philo_s < 60 || (ac == 6 && dt->philo_f < 0))
			return (NOT_ACCEPT_INPUT);
	return (PROGRAM_OK);
}

static int	get_val(const char *s, t_dt *dt)
{
	if (!s || !(*s))
		dt->err = EMPTY_STR_PASSED;
	if (!dt->err && !isstrnum(s))
		dt->err = NOT_A_NUMBER;
	if (!dt->err && m_strlen(s) > 10)
		dt->err = OVER_INT_LEN;
	if (!dt->err)
		return (ft_atoi_m(s));
	return (-1);
}

static int	m_strlen(const char *s)
{
	int	i;

	i = 0;
	while (*s++ && i < 10)
		i++;
	return (i);
}

static int	isstrnum(const char *str)
{
	while (*str >= '0' && *str++ <= '9')
	{
		if (*str == '\0')
			return (1);
	}
	return (0);
}

static int	ft_atoi_m(const char *s)
{
	int	res;

	res = 0;
	while (*s)
	{
		res *= 10;
		res += *s - '0';
		s++;
	}
	return (res);
}
