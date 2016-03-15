/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:29:35 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/14 22:23:46 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		add_elem(t_stack *stack, int nb)
{
	t_elem	*new;

	if (!(new = (t_elem *)malloc(sizeof(*new))))
		error(1);
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
		new->prev = NULL;
		stack->top->prev = new;
		new->next = stack->top;
		new = stack->top;
	}
	return (0);
}
