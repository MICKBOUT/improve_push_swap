/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/12 23:32:31 by mboutte           #+#    #+#             */
/*   Updated: 2026/01/13 00:00:10 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

static int	add_node(t_stack *stack, int nb)
{
	t_node	*new;
	t_node	*last;

	new = malloc(sizeof(t_node));
	if (!new)
		return (-1);
	new->value = nb;
	new->next = NULL;
	if (stack->tails)
	{
		last = stack->tails;
		new->next = NULL;
		new->prev = last;
		last->next = new;
	}
	else
	{
		stack->head = new;
		new->prev = NULL;
	}
	stack->size++;
	stack->tails = new;
	return (1);
}

static int	get_number(char **str, t_stack *a)
{
	long int	all;
	int			sign;

	all = 0;
	sign = 1;
	while ((**str >= 9 && **str <= 13) || **str == 32)
		(*str)++;
	while (**str == '-' || **str == '+')
	{
		if (**str == '-')
			sign = -1;
		(*str)++;
	}
	if (!('0' <= **str && **str <= '9'))
		return (-1);
	while ('0' <= **str && **str <= '9')
	{
		all = all * 10 + (**str) - '0';
		if ((sign == 1 && all > 2147483647) || (sign == -1 && all > 2147483648))
			return (-1);
		(*str)++;
	}
	add_node(a, ((int)all) * sign);
	return (0);
}

static int	ft_atoi_stack(char *str, t_stack *a)
{
	while (*str)
		get_number(&str, a);
	return (0);
}

int	create_strack(t_stack *a, int i, int ac, char **av)
{
	int	status;

	status = 0;
	status = ft_atoi_stack(av[i], a);
	i++;
	while (i < ac && status != -1)
	{
		status = ft_atoi_stack(av[i], a);
		i++;
	}
	return (status);
}
