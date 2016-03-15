/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 16:37:14 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/14 20:09:37 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init_flag(t_flag *flag)
{
	flag->c = 0;
	flag->v = 0;
	return (0);
}

int	init_stack(t_stack *stack)
{
	stack->nb_elem = 0;
	stack->top = NULL;
	stack->bot = NULL;
	return (0);
}
