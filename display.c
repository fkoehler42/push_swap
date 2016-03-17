/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 15:26:33 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 18:18:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_total_op(t_flag *flag, int nb_op)
{
	if (flag->i || (flag->o && flag->v))
		ft_printf("%d operation(s)\n", nb_op);
	else if (flag->o)
		ft_printf("\n%d operation(s)\n", nb_op);
	else if (!flag->v)
		ft_putchar('\n');
}

void	put_op(t_flag *flag, char *op_name)
{
	if (flag->v)
	{
		ft_putchar('\n');
		ft_putendl(op_name);
		put_stacks(flag);
	}
	else
		ft_putstr(op_name);
}

void	put_stacks(t_flag *flag)
{
	t_elem *tmp1;
	t_elem *tmp2;

	tmp1 = flag->stack_a->top;
	tmp2 = flag->stack_b->top;
	ft_printf("----{  Stack a  }------{  Stack b  }----\n");
	while (tmp1 || tmp2)
	{
		if (tmp1 && tmp2)
			ft_printf("----{%11d}------{%11d}----\n", tmp1->nb, tmp2->nb);
		else if (tmp1)
			ft_printf("----{%11d}------{           }----\n", tmp1->nb);
		else if (tmp2)
			ft_printf("----{           }------{%11d}----\n", tmp2->nb);
		if (tmp1)
			tmp1 = tmp1->next;
		if (tmp2)
			tmp2 = tmp2->next;
	}
}
