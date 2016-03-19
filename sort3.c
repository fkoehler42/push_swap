/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/19 15:30:05 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/19 23:33:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_max(t_stack *stack)
{
	int		i;
	int		max;
	t_elem	*tmp;

	i = 0;
	max = -2147483648;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->nb > max)
			max = tmp->nb;
		tmp = tmp->next;
	}
	tmp = stack->top;
	while (tmp->nb < max && ++i)
		tmp = tmp->next;
	return (i);
}
static int	search_to_place_top(t_stack *stack, t_elem *top)
{
	int		i;
	int		target;
	t_elem	*tmp;

	i = 0;
	target = -2147483648;
	tmp = stack->top;
	while (tmp)
	{
		if (tmp->nb < top->nb && tmp->nb > target)
			target = tmp->nb;
		tmp = tmp->next;
	}
	if (target == -2147483648)
		return (search_max(stack));
	tmp = stack->top;
	while (tmp->nb != target && ++i)
		tmp = tmp->next;
	return (i);
}

int			rotate_to_max(t_flag *flag, t_stack *stack)
{
	int		i;
	int		op;

	i = 0;
	op = 0;
	if ((i = search_max(stack)) <= (stack->nb_elem / 2))
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

static int	rotate_to_place_top(t_flag *flag, t_stack *stack, t_elem *top)
{
	int		i;
	int		op;

	i = 0;
	op = 0;
	if ((i = search_to_place_top(stack, top)) <= (stack->nb_elem / 2))
	{
		while (i-- && ++op)
		{
			rotate(stack, 0);
			put_op(flag, "rb ");
		}
	}
	else
	{
		while (i++ < stack->nb_elem && ++op)
		{
			rotate(stack, 1);
			put_op(flag, "rrb ");
		}
	}
	return (op);
}

int			sorting_algo3(t_flag *flag)
{
	int		op;

	op = 0;
	while (op < 2 && ++op)
	{
		push(flag->stack_a, flag->stack_b);
		put_op(flag, "pb ");
	}
	while (flag->stack_a->nb_elem)
	{
		op += rotate_to_place_top(flag, flag->stack_b, flag->stack_a->top);
		op += push(flag->stack_a, flag->stack_b);
		put_op(flag, "pb ");
	}
	op += rotate_to_max(flag, flag->stack_b);
	op += push_all(flag, 'a');
	return (op);
}
