/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interactive.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/17 16:47:27 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/17 20:58:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "get_next_line.h"

static int	handle_input1(t_flag *flag, char *input)
{
	if ((ft_strcmp(input, "rr") == 0) || (ft_strcmp(input, "RR") == 0))
	{
		rotate(flag->stack_a, 0);
		rotate(flag->stack_b, 0);
	}
	else if ((ft_strcmp(input, "rrr") == 0) || (ft_strcmp(input, "RRR") == 0))
	{
		rotate(flag->stack_a, 1);
		rotate(flag->stack_b, 1);
	}
	else if ((ft_strcmp(input, "c") == 0) || (ft_strcmp(input, "C") == 0))
	{
		ft_putstr("Operations list :\npa/pb : push the top of b to a/a to b\n");
		ft_putstr("sa/sb/ss : swap the first and second on a/b/both\n");
		ft_putstr("ra/rb/rr : rotate up a/b/both\n");
		ft_putstr("rra/rrb/rrr : rotate down a/b/both\n");
		return (0);
	}
	else
	{
		ft_printf("Error : '%s' is not a valid operation\n", input);
		ft_putstr("Reminder :\nc : see operations\nv : see stacks\nq : quit\n");
		return (0);
	}
	return (1);
}
static int	handle_input(t_flag *flag, char *input)
{
	if ((ft_strcmp(input, "sa") == 0) || (ft_strcmp(input, "SA") == 0))
		swap(flag->stack_a);
	else if ((ft_strcmp(input, "sb") == 0) || (ft_strcmp(input, "SB") == 0))
		swap(flag->stack_b);
	else if ((ft_strcmp(input, "ss") == 0) || (ft_strcmp(input, "SS") == 0))
	{
		swap(flag->stack_a);
		swap(flag->stack_b);
	}
	else if ((ft_strcmp(input, "pa") == 0) || (ft_strcmp(input, "PA") == 0))
		push(flag->stack_b, flag->stack_a);
	else if ((ft_strcmp(input, "pb") == 0) || (ft_strcmp(input, "PB") == 0))
		push(flag->stack_a, flag->stack_b);
	else if ((ft_strcmp(input, "ra") == 0) || (ft_strcmp(input, "RA") == 0))
		rotate(flag->stack_a, 0);
	else if ((ft_strcmp(input, "rb") == 0) || (ft_strcmp(input, "RB") == 0))
		rotate(flag->stack_b, 0);
	else if ((ft_strcmp(input, "rra") == 0) || (ft_strcmp(input, "RRA") == 0))
		rotate(flag->stack_a, 1);
	else if ((ft_strcmp(input, "rrb") == 0) || (ft_strcmp(input, "RRB") == 0))
		rotate(flag->stack_b, 1);
	else
		return (handle_input1(flag, input));
	return (1);
}

static int	handle_round(t_flag *flag, int op)
{
	int		ret;
	char	*input;

	ret = 0;
	input = NULL;
	ft_putstr("\nChoose an operation : ");
	get_next_line(0, &input);
	if (!input[0])
		ret = 0;
	else if ((ft_strcmp(input, "q") == 0) || (ft_strcmp(input, "Q") == 0))
		ret = -1;
	else if ((ft_strcmp(input, "v") == 0) || (ft_strcmp(input, "V") == 0))
	{
		put_stacks(flag);
		ret = 0;
	}
	else if (handle_input(flag, input) == 1)
	{
		put_stacks(flag);
		put_total_op(flag, op);
		ret = 1;
	}
	free(input);
	return (ret);
}

int			interactive_mode(t_flag *flag)
{
	int		i;
	int		op;

	i = 0;
	op = 1;
	ft_putstr("\nWelcome into the interactive mode of Push Swap ! Enjoy :-)\n");
	ft_putstr("(Press 'c' to display the operations list, ");
	ft_putstr("'v' to display the stacks or 'q' to quit)\n\n");
	put_stacks(flag);
	while (issorted_stack(flag) < 0)
	{
		if ((i = handle_round(flag, op)) < 0)
		{
			ft_putstr("Game Over :-(\n");
			return (0);
		}
		op += i;
	}
	ft_putstr("Congratulations ! The stack is correctly sorted\n");
	return (0);
}
