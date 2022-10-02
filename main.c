/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/01 16:00:31 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 21:47:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static void	ft_push_swap(t_arg *arg)
{
	if (arg->a->size == 2)
		ft_sort_two(arg, 'a');
	else if (arg->a->size == 3)
		ft_sort_three_a(arg);
	else if (arg->a->size == 4)
		ft_sort_four_a(arg);
	else if (arg->a->size == 5)
		ft_sort_five_a(arg);
	else
		ft_sort(arg);
}

int	main(int argc, char *argv[])
{
	t_arg	*arg;

	if (argc <= 1)
		return (0);
	arg = (t_arg *)malloc(sizeof(t_arg));
	if (!arg)
		return (0);
	arg->a = ft_stacknew();
	arg->b = ft_stacknew();
	get_stack_args(arg, argc, argv);
	check_element_overlap(arg);
	check_element_sorted(arg);
	ft_push_swap(arg);
	return (0);
}
