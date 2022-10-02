/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_doop_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnoh <jnoh@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/20 10:26:45 by jnoh              #+#    #+#             */
/*   Updated: 2022/09/20 22:59:26 by jnoh             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap_bonus.h"
#include "../libft/libft.h"

int	ft_check_push(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "pa\n", 3) == 0)
	{
		push(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "pb\n", 3) == 0)
	{
		push(arg, 'b', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_swap(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sa\n", 3) == 0)
	{
		swap(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "sb\n", 3) == 0)
	{
		swap(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "ss\n", 3) == 0)
	{
		swap(arg, 's', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_rotate(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 3 && ft_strncmp(line, "ra\n", 3) == 0)
	{
		rotate(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "rb\n", 3) == 0)
	{
		rotate(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 3 && ft_strncmp(line, "rr\n", 3) == 0)
	{
		rotate(arg, 'r', 0);
		ret = 1;
	}
	return (ret);
}

int	ft_check_rrotate(t_arg *arg, char *line)
{
	int	ret;

	ret = 0;
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rra\n", 4) == 0)
	{
		reverse_rotate(arg, 'a', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rrb\n", 4) == 0)
	{
		reverse_rotate(arg, 'b', 0);
		ret = 1;
	}
	if (ft_strlen(line) == 4 && ft_strncmp(line, "rrr\n", 4) == 0)
	{
		reverse_rotate(arg, 'r', 0);
		ret = 1;
	}
	return (ret);
}
