/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/16 16:21:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	search_min(t_stack *a)
{
	int		i;
	int		min;
	t_elem	*tmp;

	i = 0;
	min = 2147483647;
	tmp = a->top;
	while (tmp)
	{
		if (tmp->nb < min)
			min = tmp->nb;
		tmp = tmp->next;
	}
	tmp = a->top;
	while (tmp->nb > min && ++i)
		tmp = tmp->next;
	return (i);
}

int			push_all(t_stack *a, t_stack *b, char *op_name)
{
	int	op;

	op = 0;
	while (a->nb_elem && ++op)
	{
		push(a, b);
		ft_putstr(op_name);
	}
	return (op);
}

int			rotate_to_min(t_stack *stack)
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
			ft_putstr("ra ");
		}
	}
	else
	{
		while (i++ < stack->nb_elem && ++op)
		{
			rotate(stack, 1);
			ft_putstr("rra ");
		}
	}
	return (op);
}
