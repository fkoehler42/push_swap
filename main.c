/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 14:41:37 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 13:41:56 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(int err_code)
{
	if (err_code == 0)
		ft_putstr_fd("Error : memory allocation failed\n", STDERR_FILENO);
	else if (err_code == 1)
		ft_putstr_fd("Error : illegal option\n", STDERR_FILENO);
	else if (err_code == 2)
		ft_putstr_fd("Error : An argument is invalid\n",
					STDERR_FILENO);
	else if (err_code == 3)
		ft_putstr_fd("Error : An argument is too large\n",
					STDERR_FILENO);
	else if (err_code == 4)
		ft_putstr_fd("Error : Two arguments are identical\n", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

int		main(int ac, char **av)
{
	int		i;
	int		op;
	t_flag	flag;
	t_stack	stack_a;
	t_stack	stack_b;

	if (ac < 2)
		return (0);
	init_stack(&stack_a);
	init_stack(&stack_b);
	init_flag(&flag, &stack_a, &stack_b);
	i = (parse_flags(&flag, ac, av));
	if ((ac - i) < 2)
		return (0);
	parse_args(&stack_a, i, ac, av);
	if (flag.v)
		put_stacks(&flag);
	op = sort_stack(&flag);
	put_total_op(&flag, op);
	return (0);
}
