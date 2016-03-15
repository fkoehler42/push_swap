/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:53:05 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 22:03:38 by fkoehler         ###   ########.fr       */
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

int		rotate(t_stack *a, int reverse)
{
	t_elem *elem;

	if (a->nb_elem < 2)
		return (-1);
	if (!reverse)
	{
		elem = a->top;
		a->bot->next = elem;
		a->top = a->top->next;
		a->top->prev = NULL;
		elem->prev = a->bot;
		a->bot = elem;
		elem->next = NULL;
	}
	else
	{
		elem = a->bot;
		a->top->prev = elem;
		a->bot = a->bot->prev;
		a->bot->next = NULL;
		elem->next = a->top;
		a->top = elem;
		elem->prev = NULL;
	}
	return (0);
}

int		swap(t_stack *a)
{
	int	tmp;

	if (a->nb_elem < 2)
		return (-1);
	tmp = a->top->nb;
	a->top->nb = a->top->next->nb;
	a->top->next->nb = tmp;
	return (0);
}
