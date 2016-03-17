/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:37:14 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 12:35:03 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_flag(t_flag *flag, t_stack *a, t_stack *b)
{
	flag->c = 0;
	flag->o = 0;
	flag->v = 0;
	flag->stack_a = a;
	flag->stack_b = b;
	return (0);
}

int	init_stack(t_stack *stack)
{
	stack->nb_elem = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (0);
}
