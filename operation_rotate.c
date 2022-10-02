/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:43:51 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 10:36:52 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	ra(t_arg *arg)
{
	t_node	*node;

	if (arg->a->size < 2)
		return (0);
	node = ft_pop(arg->a);
	ft_pushback(arg->a, node);
	return (1);
}

static int	rb(t_arg *arg)
{
	t_node	*node;

	if (arg->b->size < 2)
		return (0);
	node = ft_pop(arg->b);
	ft_pushback(arg->b, node);
	return (1);
}

int	rotate(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		if (ra(arg) && print)
			ft_putstr_fd("ra\n", 1);
	}
	if (type == 'b')
	{
		if (rb(arg) && print)
			ft_putstr_fd("rb\n", 1);
	}
	if (type == 'r')
	{
		result = ra(arg) + rb(arg);
		if (result != 0 && print)
			ft_putstr_fd("rr\n", 1);
	}
	return (1);
}
