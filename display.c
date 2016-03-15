/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:26:33 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 18:45:33 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_stacks(t_stack *a, t_stack *b)
{
	t_elem *tmp1;
	t_elem *tmp2;

	tmp1 = a->top;
	tmp2 = b->top;
	ft_printf("----///Stack a///------///Stack b///----\n");
	while (tmp1 || tmp2)
	{
		if (tmp1 && tmp2)
		{
			ft_printf("----(%11d)------(%11d)----\n", tmp1->nb, tmp2->nb);
			tmp1 = tmp1->next;
			tmp2 = tmp2->next;
		}
		else if (tmp1)
		{
			ft_printf("----(%11d)------(           )----\n", tmp1->nb);
			tmp1 = tmp1->next;
		}
		else if (tmp2)
		{
			ft_printf("----(           )------(%11d)----\n", tmp2->nb);
			tmp2 = tmp2->next;
		}
	}
	ft_putchar('\n');
}
