/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:32:01 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/19 23:41:20 by fkoehler         ###   ########.fr       */
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

	i = 0;
	if (flag->v)
		put_stacks(flag);
	if (((i = search_not_sorted_elem(flag->stack_a)) == (flag->stack_a->nb_elem - 2))
		&& (flag->stack_a->bot->nb < flag->stack_a->bot->prev->nb))
		op = sorting_algo2(flag);
	else
		op = sorting_algo1(flag);
	return (op);
}
