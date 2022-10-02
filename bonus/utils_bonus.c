/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 13:09:43 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 11:53:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"

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
	}
	if (arg->b)
	{
		if (arg->b->size)
			free_stack(arg->b);
	}
	free(arg->a);
	free(arg->b);
	free(arg);
}
