/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/20 20:05:16 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			issorted_stack(t_flag *flag)
{
	t_elem *tmp;

	tmp = flag->stack_a->top;
	if (flag->stack_b->nb_elem)
		return (-1);
	while (tmp->next)
	{
		if (tmp->nb > tmp->next->nb)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static int	rotate_to_swap(t_flag *flag, t_stack *stack)
{
	int	i;
	int	op;

	i = 0;
	op = 0;
	if ((i = search_not_sorted_elem(stack)) <= (stack->nb_elem / 2))
	{
		while (i-- && ++op)
		{
			rotate(stack, 0);
			put_op(flag, "ra ");
		}
	}
	else
	{
		while (i++ < stack->nb_elem && ++op)
		{
			rotate(stack, 1);
			put_op(flag, "rra ");
		}
	}
	return (op);
}

int			sorting_algo2(t_flag *flag)
{
	int		op;

	op = 0;
	while (issorted_stack(flag) < 0 && ++op)
	{
		op += rotate_to_swap(flag, flag->stack_a);
		swap(flag->stack_a);
		put_op(flag, "sa ");
		op += rotate_to_min(flag, flag->stack_a);
	}
	return (op);
}
