/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 22:19:28 by fkoehler         ###   ########.fr       */
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

int			sort_stack(t_stack *a, t_stack *b)
{
	int		i;
	int		op;

	op = 0;
	while (a->nb_elem && ++op)
	{
		i = 0;
		if ((i = search_min(a)) <= (a->nb_elem / 2))
		{
			while (i-- && ++op)
			{
				rotate(a, 0);
				ft_putstr("ra ");
			}
		}
		else
		{
			while (i++ < a->nb_elem && ++op)
			{
				rotate(a, 1);
				ft_putstr("rra ");
			}
		}
		push(a, b);
		ft_putstr("pb ");
	}
	while (b->nb_elem && ++op)
	{
		push(b, a);
		ft_putstr("pa ");
	}
	ft_putchar('\n');
	put_stacks(a, b);
	ft_printf("%d operations", op);
	return (0);
}
