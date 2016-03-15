/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:35 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 17:31:56 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_elem(t_stack *stack, int nb)
{
	t_elem	*new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		error(0);
	new->nb = nb;
	if (!stack->bot)
	{
		stack->bot = new;
		stack->top = new;
		new->prev = NULL;
		new->next = NULL;
	}
	else
	{
		stack->top->prev = new;
		new->next = stack->top;
		new->prev = NULL;
		stack->top = new;
	}
	stack->nb_elem++;
	return (0);
}
