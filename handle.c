/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 19:02:03 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int			sort_stack(t_stack *a, t_stack *b)
{
	if (issorted_stack(a, b) < 0)
		put_stacks(a, b);
	rotate(a);
	put_stacks(a, b);
	return (0);
}
