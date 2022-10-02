/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rrotate_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:44:14 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 11:51:13 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../libft/libft.h"

static int	rra(t_arg *arg)
{
	t_node	*node;

	if (arg->a->size < 2)
		return (0);
	node = arg->a->bottom;
	arg->a->bottom->next->prev = 0;
	arg->a->bottom = arg->a->bottom->next;
	arg->a->size--;
	ft_push(arg->a, node);
	return (1);
}

static int	rrb(t_arg *arg)
{
	t_node	*node;

	if (arg->b->size < 2)
		return (0);
	node = arg->b->bottom;
	arg->b->bottom->next->prev = 0;
	arg->b->bottom = arg->b->bottom->next;
	arg->b->size--;
	ft_push(arg->b, node);
	return (1);
}

int	reverse_rotate(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		if (rra(arg) && print)
			ft_putstr_fd("rra\n", 1);
	}
	if (type == 'b')
	{
		if (rrb(arg) && print)
			ft_putstr_fd("rrb\n", 1);
	}
	if (type == 'r')
	{
		result = rra(arg) + rrb(arg);
		if (result != 0 && print)
			ft_putstr_fd("rrr\n", 1);
	}
	return (1);
}
