/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/19 15:50:15 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 10:39:13 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_two(t_arg *arg, char type)
{
	if (type == 'a')
	{
		if (arg->a->top->data > arg->a->top->prev->data)
			swap(arg, 'a', 1);
	}
	else if (type == 'b')
	{
		if (arg->b->top->data < arg->b->top->prev->data)
			swap(arg, 'b', 1);
	}
	return ;
}

void	ft_sort_three_a(t_arg *arg)
{
	int	data[3];

	data[0] = arg->a->top->data;
	data[1] = arg->a->top->prev->data;
	data[2] = arg->a->top->prev->prev->data;
	if (data[0] < data[2] && data[2] < data[1])
	{
		rotate(arg, 'a', 1);
		swap(arg, 'a', 1);
		reverse_rotate(arg, 'a', 1);
	}
	else if (data[1] < data[0] && data[0] < data[2])
		swap(arg, 'a', 1);
	else if (data[2] < data[0] && data[0] < data[1])
		reverse_rotate(arg, 'a', 1);
	else if (data[1] < data[2] && data[2] < data[0])
		rotate(arg, 'a', 1);
	else if (data[2] < data[1] && data[1] < data[0])
	{
		swap(arg, 'a', 1);
		reverse_rotate(arg, 'a', 1);
	}
}

void	ft_sort_four_a(t_arg *arg)
{
	t_node	*node;
	int		small;

	node = arg->a->top;
	small = ft_get_stack_min(arg->a);
	while (node)
	{
		if (small == node->data)
			break ;
		rotate(arg, 'a', 1);
		node = arg->a->top;
	}
	push(arg, 'b', 1);
	ft_sort_three_a(arg);
	push(arg, 'a', 1);
}

void	ft_sort_five_a(t_arg *arg)
{
	int	mid;
	int	pb_cnt;

	pb_cnt = 0;
	mid = ft_find_five_mid(arg->a);
	while (pb_cnt < 2)
	{
		if (arg->a->top->data < mid)
			pb_cnt += push(arg, 'b', 1);
		else
			rotate(arg, 'a', 1);
	}
	ft_sort_three_a(arg);
	ft_sort_two(arg, 'b');
	push(arg, 'a', 1);
	push(arg, 'a', 1);
}

int	ft_find_index_a(t_arg *arg, int data)
{
	int		i;
	t_node	*node;

	if (data < ft_get_stack_min(arg->a))
		i = ft_stack_find(arg->a, ft_get_stack_min(arg->a));
	else if (data > ft_get_stack_max(arg->a))
		i = ft_stack_find(arg->a, ft_get_stack_max(arg->a)) + 1;
	else
	{
		node = arg->a->top;
		i = 1;
		while (node->prev)
		{
			if (node->data < data && data < node->prev->data)
				break ;
			node = node->prev;
			i++;
		}
	}
	if (i >= (arg->a->size + 1) / 2)
		i = (arg->a->size - i) * (-1);
	return (i);
}
