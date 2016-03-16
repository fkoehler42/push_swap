/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/16 16:35:05 by fkoehler         ###   ########.fr       */
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

int			sort_stack(t_flag *flag, t_stack *a, t_stack *b)
{
	int		op;

	op = 0;
	while (a->nb_elem && ++op)
	{
		op += rotate_to_min(a);
		push(a, b);
		ft_putstr("pb ");
	}
	op += push_all(b, a, "pa ");
	ft_putchar('\n');
	ft_printf("%d operations\n", op);
	return (0);
}
