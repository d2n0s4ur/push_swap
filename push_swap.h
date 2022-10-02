/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:37 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 11:55:01 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>

# define INT_MAX 2147483647
# define INT_MIN -2147483648

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	struct s_node	*top;
	struct s_node	*bottom;
	int				size;
}	t_stack;

typedef struct s_arg
{
	struct s_stack	*a;
	struct s_stack	*b;
	int				pivot[2];
}	t_arg;

t_node	*ft_nodenew(int data);
void	ft_push(t_stack *stack, t_node *node);
t_node	*ft_pop(t_stack *stack);
t_stack	*ft_stacknew(void);
int		swap(t_arg *arg, char type, int print);
int		push(t_arg *arg, char type, int print);
int		rotate(t_arg *arg, char type, int print);
int		reverse_rotate(t_arg *arg, char type, int print);
void	print_error_exit(int code, t_arg *arg);
void	ft_pushback(t_stack *stack, t_node *node);
void	ft_free(t_arg *arg);
void	ft_sort(t_arg *arg);
void	ft_sort_three_a(t_arg *arg);
void	ft_sort_four_a(t_arg *arg);
void	ft_sort_five_a(t_arg *arg);
void	get_stack_args(t_arg *arg, int argc, char *argv[]);
void	check_element_sorted(t_arg *arg);
void	check_element_overlap(t_arg *arg);
void	ft_sort_two(t_arg *arg, char type);
int		ft_find_five_mid(t_stack *stack);
void	ft_sort_three_a_mini(t_arg *arg);
int		ft_abs(int data);
int		ft_stack_find(t_stack *stack, int data);
int		ft_get_stack_min(t_stack *stack);
int		ft_get_stack_max(t_stack *stack);
void	ft_rotate_indiv(t_arg *arg, int count, char type);
void	ft_rotate_all(t_arg *arg, int ra_cnt, int rb_cnt);
void	ft_get_pivot(t_arg *arg);
void	ft_last_rotate(t_arg *arg);
int		ft_find_index_a(t_arg *arg, int data);

#endif
