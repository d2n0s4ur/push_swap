/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 15:55:37 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 11:54:43 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
void	print_error_exit(t_arg *arg);
void	ft_pushback(t_stack *stack, t_node *node);
void	ft_free(t_arg *arg);
void	get_stack_args(t_arg *arg, int argc, char *argv[]);
void	check_element_sorted(t_arg *arg);
void	check_element_overlap(t_arg *arg);
int		ft_check_push(t_arg *arg, char *line);
int		ft_check_swap(t_arg *arg, char *line);
int		ft_check_rotate(t_arg *arg, char *line);
int		ft_check_rrotate(t_arg *arg, char *line);

#endif
