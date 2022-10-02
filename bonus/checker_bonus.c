/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 01:11:01 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 21:47:48 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../libft/libft.h"

static void	print_exit(char *str, int status)
{
	ft_putstr_fd(str, 1);
	exit(status);
}

static void	ft_check_sorted(t_arg *arg)
{
	t_node	*node;
	int		flag;

	node = arg->a->top;
	flag = 1;
	while (node->prev)
	{
		if (node->data > node->prev->data)
		{
			flag = 0;
			break ;
		}
		node = node->prev;
	}
	ft_free(arg);
	if (flag)
		print_exit("OK\n", 0);
	else
		print_exit("KO\n", 0);
	exit(0);
}

static void	ft_do_sort(t_arg *arg)
{
	char	*line;
	int		result;

	while (1)
	{
		line = get_next_line(0);
		if (!line)
			ft_check_sorted(arg);
		result = ft_check_push(arg, line) + ft_check_swap(arg, line) + \
			ft_check_rotate(arg, line) + ft_check_rrotate(arg, line);
		free(line);
		if (result != 1)
			print_error_exit(arg);
	}
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
	ft_do_sort(arg);
	return (0);
}
