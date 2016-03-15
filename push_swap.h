/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:10:22 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/14 22:28:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <libft.h>
# include <ft_printf.h>

typedef struct		s_elem
{
	int				nb;
	struct s_elem	*prev;
	struct s_elem	*next;
}					t_elem;

typedef struct		s_stack
{
	int				nb_elem;
	struct s_elem	*top;
	struct s_elem	*bot;
}					t_stack;

typedef struct		s_flag
{
	int				c;
	int				v;
}					t_flag;

int					init_flag(t_flag *flag);
int					init_stack(t_stack *stack);

void				error(int err_code);
int					parse_flags(t_flag *flag, int ac, char **av);
int					parse_args(t_stack *stack, int i, int ac, char **av);

int					add_elem(t_stack *stack, int nb);

#endif
