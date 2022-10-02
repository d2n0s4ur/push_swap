/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:09:43 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/23 01:03:13 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

void	print_error_exit(int code, t_arg *arg)
{
	if (code == 1)
		write(2, "Error\n", 6);
	ft_free(arg);
	exit(1);
}

static void	free_stack(t_stack *stack)
{
	t_node	*node;
	t_node	*to_free;

	node = stack->top;
	while (node)
	{
		to_free = node;
		node = node->next;
		free(to_free);
	}
}

void	ft_free(t_arg *arg)
{
	if (!arg)
		return ;
	if (arg->a)
	{
		if (arg->a->size)
			free_stack(arg->a);
		free(arg->a);
	}
	if (arg->b)
	{
		if (arg->b->size)
			free_stack(arg->b);
		free(arg->b);
	}
	free(arg);
}

int	ft_abs(int data)
{
	if (data < 0)
		return (data * (-1));
	return (data);
}

void	ft_get_pivot(t_arg *arg)
{
	t_node	*node;
	t_node	*comp;
	int		count;

	node = arg->a->top;
	while (node)
	{
		comp = arg->a->top;
		count = 0;
		while (comp)
		{
			if (node->data > comp->data)
				count++;
			comp = comp->prev;
		}
		if (count == arg->a->size / 3)
			arg->pivot[0] = node->data;
		if (count == (arg->a->size * 2) / 3)
			arg->pivot[1] = node->data;
		node = node->prev;
	}
}
