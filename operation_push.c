/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/04 12:42:52 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 10:36:39 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	pa(t_arg *arg)
{
	t_node	*new;

	if (arg->b->size < 1)
		return (0);
	new = ft_pop(arg->b);
	ft_push(arg->a, new);
	return (1);
}

static int	pb(t_arg *arg)
{
	t_node	*new;

	if (arg->a->size < 1)
		return (0);
	new = ft_pop(arg->a);
	ft_push(arg->b, new);
	return (1);
}

int	push(t_arg *arg, char type, int print)
{
	int	result;

	if (type == 'a')
	{
		result = pa(arg);
		if (result && print)
			ft_putstr_fd("pa\n", 1);
	}
	if (type == 'b')
	{
		result = pb(arg);
		if (result && print)
			ft_putstr_fd("pb\n", 1);
	}
	return (1);
}
