/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 17:04:04 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 11:51:15 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../libft/libft.h"

static int	sa(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	if (arg->a->size < 2)
		return (0);
	node1 = ft_pop(arg->a);
	node2 = ft_pop(arg->a);
	ft_push(arg->a, node1);
	ft_push(arg->a, node2);
	return (1);
}

static int	sb(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	if (arg->b->size < 2)
		return (0);
	node1 = ft_pop(arg->b);
	node2 = ft_pop(arg->b);
	ft_push(arg->b, node1);
	ft_push(arg->b, node2);
	return (1);
}

int	swap(t_arg *arg, char type, int print)
{
	if (type == 'a')
	{
		if (sa(arg) && print)
			ft_putstr_fd("sa\n", 1);
	}
	if (type == 'b')
	{
		if (sb(arg) && print)
			ft_putstr_fd("sb\n", 1);
	}
	if (type == 's')
	{
		if (sa(arg) + sb(arg) != 0 && print)
			ft_putstr_fd("ss\n", 1);
	}
	return (0);
}
