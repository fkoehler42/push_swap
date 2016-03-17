/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 14:02:54 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
/*
static int	issorted_stack(t_stack *a, t_stack *b)
{
	t_elem *tmp;

	tmp = a->top;
	if (b->top)
		return (-1);
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}
*/

int			sort_stack(t_flag *flag)
{
	int		op;

	op = 0;
	while ((flag->stack_a->nb_elem > 1) && ++op)
	{
		op += rotate_to_min(flag, flag->stack_a);
		push(flag->stack_a, flag->stack_b);
		put_op(flag, "pb ");
	}
	op += push_all(flag, 'a');
	return (op);
}
