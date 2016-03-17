/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 12:49:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min(t_stack *stack)
{
	int		i;
	int		min;
	t_elem	*tmp;

	i = 0;
	min = 2147483647;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	tmp = stack->top;
	while (tmp->nb > min && ++i)
		tmp = tmp->next;
	return (i);
}

int			push_all(t_flag *flag, char to_push)
{
	int	op;

	op = 0;
	if (to_push == 'a')
	{
		while (flag->stack_b->nb_elem && ++op)
		{
			push(flag->stack_b, flag->stack_a);
			put_op(flag, "pa ");
		}
	}
	else if (to_push == 'b')
	{
		while (flag->stack_a->nb_elem && ++op)
		{
			push(flag->stack_a, flag->stack_b);
			put_op(flag, "pb ");
		}
	}
	return (op);
}

int			rotate_to_min(t_flag *flag, t_stack *stack)
{
	int		i;
	int		op;

	i = 0;
	op = 0;
	if ((i = search_min(stack)) <= (stack->nb_elem / 2))
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
