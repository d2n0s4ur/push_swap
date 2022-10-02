/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 14:44:17 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 01:04:42 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

int	ft_find_five_mid(t_stack *stack)
{
	int		data[5];
	int		i;
	int		j;
	int		check;

	data[0] = stack->top->data;
	data[1] = stack->top->prev->data;
	data[2] = stack->top->prev->prev->data;
	data[3] = stack->bottom->next->data;
	data[4] = stack->bottom->data;
	i = 0;
	while (i < 5)
	{
		j = 0;
		check = 0;
		while (j < 5)
		{
			check += (int)(data[i] < data[j]);
			j++;
		}
		if (check == 2)
			return (data[i]);
		i++;
	}
	return (0);
}

int	ft_stack_find(t_stack *stack, int data)
{
	int		i;
	t_node	*node;

	i = 0;
	node = stack->top;
	while (node)
	{
		if (node->data == data)
			break ;
		node = node->prev;
		i++;
	}
	return (i);
}

int	ft_get_stack_min(t_stack *stack)
{
	int		ret;
	t_node	*node;

	node = stack->top;
	ret = node->data;
	while (node)
	{
		if (ret > node->data)
			ret = node->data;
		node = node->prev;
	}
	return (ret);
}

int	ft_get_stack_max(t_stack *stack)
{
	int		ret;
	t_node	*node;

	node = stack->top;
	ret = node->data;
	while (node)
	{
		if (ret < node->data)
			ret = node->data;
		node = node->prev;
	}
	return (ret);
}

void	ft_last_rotate(t_arg *arg)
{
	int	min_index;

	min_index = ft_stack_find(arg->a, ft_get_stack_min(arg->a));
	if (min_index >= (arg->a->size + 1) / 2)
		min_index = (arg->a->size - min_index) * (-1);
	ft_rotate_indiv(arg, min_index, 'a');
}
