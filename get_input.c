/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/18 17:20:47 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 21:47:49 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "./libft/libft.h"

static int	ft_isspace(char c)
{
	if (c == '\t' || c == '\n' || c == '\v')
		return (1);
	if (c == '\f' || c == '\r' || c == ' ')
		return (1);
	return (0);
}

static int	ft_atodata(const char *str, t_arg *arg, int *index)
{
	int			minus;
	long long	result;
	int			len;

	minus = 1;
	len = 0;
	if (str[*index] == '-' || str[*index] == '+')
		minus = minus - (str[(*index)++] == '-') * 2;
	result = 0;
	while (ft_isdigit(str[*index]))
	{
		result = result * 10 + (str[(*index)++] - '0');
		len++;
	}
	result = result * (minus);
	if (len > 10 || result < INT_MIN || result > INT_MAX || len == 0)
		print_error_exit(1, arg);
	return ((int)result);
}

void	get_stack_args(t_arg *arg, int argc, char *argv[])
{
	int	i;
	int	j;
	int	flag;

	i = 0;
	while (++i < argc)
	{
		j = 0;
		flag = 0;
		while (argv[i][j])
		{
			while (argv[i][j] && ft_isspace(argv[i][j]))
				j++;
			if (!argv[i][j])
				break ;
			if (!ft_isdigit(argv[i][j]) && \
				argv[i][j] != '-' && argv[i][j] != '+')
				print_error_exit(1, arg);
			ft_pushback(arg->a, ft_nodenew(ft_atodata(argv[i], arg, &j)));
			flag = 1;
		}
		if (!flag)
			print_error_exit(1, arg);
	}
}

void	check_element_sorted(t_arg *arg)
{
	t_node	*node;

	node = arg->a->top;
	while (node->prev)
	{
		if (node->data > node->prev->data)
			return ;
		node = node->prev;
	}
	ft_free(arg);
	exit(0);
}

void	check_element_overlap(t_arg *arg)
{
	t_node	*node1;
	t_node	*node2;

	node1 = arg->a->top;
	while (node1)
	{
		node2 = node1->prev;
		while (node2)
		{
			if (node1->data == node2->data)
				print_error_exit(1, arg);
			node2 = node2->prev;
		}
		node1 = node1->prev;
	}
}
