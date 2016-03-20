/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/20 19:50:31 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int			search_not_sorted_elem(t_stack *stack)
{
	int		i;
	t_elem	*tmp;

	i = 0;
	tmp = stack->top->next;
	while (tmp && tmp->nb > tmp->prev->nb && ++i)
		tmp = tmp->next;
	return (i);
}

int			sort_stack(t_flag *flag)
{
	int		op;
	int		i;

	op = 0;
	i = 0;
	if (flag->v)
		put_stacks(flag);
	if (flag->stack_a->nb_elem > 1
		&& flag->stack_a->top->nb > flag->stack_a->top->next->nb && ++op)
	{
		swap(flag->stack_a);
		put_op(flag, "sa ");
	}
	if (((i = search_not_sorted_elem(flag->stack_a))
			== (flag->stack_a->nb_elem - 2))
			&& (flag->stack_a->bot->nb < flag->stack_a->bot->prev->nb))
		op += sorting_algo2(flag);
	else if (issorted_stack(flag) < 0)
		op += sorting_algo1(flag);
	return (op);
}
