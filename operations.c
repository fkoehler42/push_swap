/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:53:05 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/16 16:03:21 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		push(t_stack *a, t_stack *b)
{
	t_elem *elem;

	if (!(elem = a->top))
		return (-1);
	if (!(a->top = a->top->next))
		a->bot = a->top;
	else
		a->top->prev = NULL;
	if (!b->top)
	{
		b->top = elem;
		b->bot = elem;
		elem->prev = NULL;
		elem->next = NULL;
	}
	else
	{
		b->top->prev = elem;
		elem->next = b->top;
		elem->prev = NULL;
		b->top = elem;
	}
	a->nb_elem--;
	b->nb_elem++;
	return (0);
}

int		rotate(t_stack *stack, int reverse)
{
	t_elem *elem;

	if (a->nb_elem < 2)
		return (-1);
	if (!reverse)
	{
		elem = stack->top;
		stack->bot->next = elem;
		stack->top = stack->top->next;
		stack->top->prev = NULL;
		elem->prev = stack->bot;
		stack->bot = elem;
		elem->next = NULL;
	}
	else
	{
		elem = stack->bot;
		stack->top->prev = elem;
		stack->bot = stack->bot->prev;
		stack->bot->next = NULL;
		elem->next = stack->top;
		stack->top = elem;
		elem->prev = NULL;
	}
	return (0);
}

int		swap(t_stack *stack)
{
	int	tmp;

	if (stack->nb_elem < 2)
		return (-1);
	tmp = stack->top->nb;
	stack->top->nb = stack->top->next->nb;
	stack->top->next->nb = tmp;
	return (0);
}
