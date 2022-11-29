/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tn_numeric.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/20 16:17:28 by nwattana          #+#    #+#             */
/*   Updated: 2022/11/29 02:27:16 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TN_NUMERIC_H
# define TN_NUMERIC_H

typedef enum e_error{
	PROGRAM_OK,
	INVALID_INPUT_AMOUNT,
	INVALID_INPUT_TYPE,
	EMPTY_STR_PASSED,
	NOT_A_NUMBER,
	OVER_INT_LEN,
	NOT_ACCEPT_INPUT,
	MALLOC_FAIL,
}		t_err;

typedef	enum s_philo_state
{
	WAITING,
	EATING,
	SLEEP,
	READY = -1,
	DIE = -2
}	t_pstate;

#endif
