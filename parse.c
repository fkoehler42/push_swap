/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 15:11:45 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/15 15:50:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	check_duplicates(t_stack *stack)
{
	t_elem *tmp;

	tmp = stack->top;
	while (tmp->next)
	{
		tmp = tmp->next;
		if (stack->top->nb == tmp->nb)
			error(4);
	}
	return (0);
}

static int	check_arg(char *arg)
{
	long	nb;

	if (arg[0] == '-' || arg[0] == '+')
	{
		if (ft_strlen(arg) > 11)
			error(3);
	}
	else
	{
		if (ft_strlen(arg) > 10)
			error(3);
	}
	nb = ft_atol(arg);
	if ((nb > 2147483647) || (nb < -2147483648))
		error(3);
	return ((int)nb);
}

int			parse_flags(t_flag *flag, int ac, char **av)
{
	int	i;
	int j;

	i = 1;
	while (i < ac && av[i][0] == '-')
	{
		j = 1;
		if (!av[i][j])
			error(2);
		else if (ft_isdigit(av[i][j]))
			return (i - 1);
		while (av[i][j])
		{
			if (av[i][j] == 'c')
				flag->c = 1;
			else if (av[i][j] == 'v')
				flag->v = 1;
			else
				error(1);
			j++;
		}
		i++;
	}
	return (i - 1);
}

int			parse_args(t_stack *stack, int i, int ac, char **av)
{
	int j;
	int	nb;

	nb = 0;
	while (--ac > i)
	{
		j = 0;
		if (av[ac][j] == '-' || av[ac][j] == '+')
			j++;
		if (!av[ac][j])
			error(2);
		while (av[ac][j])
		{
			if (!ft_isdigit(av[ac][j]))
				error(2);
			j++;
		}
		nb = check_arg(av[ac]);
		add_elem(stack, nb);
		check_duplicates(stack);
	}
	return (0);
}
