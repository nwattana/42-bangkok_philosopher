/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:13:22 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/20 17:02:47 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		get_val(const char *s, t_dt *dt);
static int		m_strlen(const char *s);
static int		ft_atoi_m(const char *s);
static int		isstrnum(const char *str);

int	collect_d(t_dt *dt, int ac, char **av)
{
	int		i;

	if (ac < 4 || ac > 5)
		return (INVALID_INPUT_AMOUNT);
	i = 1;
	dt->philo_f = -1;
	dt->philo_c = get_val(av[i++], dt);
	dt->philo_l = get_val(av[i++], dt);
	dt->philo_e = get_val(av[i++], dt);
	dt->philo_s = get_val(av[i++], dt);
	if (ac == 5)
		dt->philo_f = get_val(av[i++], dt);
	return (dt->err);
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
