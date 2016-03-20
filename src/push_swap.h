/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/12 14:10:22 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/20 19:59:36 by fkoehler         ###   ########.fr       */
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
	int				i;
	int				o;
	int				v;
	struct s_stack	*stack_a;
	struct s_stack	*stack_b;
}					t_flag;

int					init_flag(t_flag *flag, t_stack *a, t_stack *b);
int					init_stack(t_stack *stack);
int					interactive_mode(t_flag *flag);

void				error(int err_code);
int					parse_flags(t_flag *flag, int ac, char **av);
int					parse_args(t_stack *stack, int i, int ac, char **av);
int					add_elem(t_stack *stack, int nb);
int					delete_stacks(t_stack *a, t_stack *b);

int					push(t_stack *a, t_stack *b);
int					swap(t_stack *stack);
int					rotate(t_stack *stack, int reverse);

int					issorted_stack(t_flag *flag);
int					sort_stack(t_flag *flag);
int					sorting_algo1(t_flag *flag);
int					sorting_algo2(t_flag *flag);
int					rotate_to_min(t_flag *flag, t_stack *stack);
int					push_all(t_flag *flag, char to_push);
int					search_not_sorted_elem(t_stack *stack);

void				put_op(t_flag *flag, char *op_name);
void				put_total_op(t_flag *flag, int nb_op);
void				put_stacks(t_flag *flag);

#endif
