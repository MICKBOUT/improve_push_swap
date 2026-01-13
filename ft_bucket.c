/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bucket.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 11:24:13 by mthetcha          #+#    #+#             */
/*   Updated: 2026/01/13 14:19:19 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_max(t_stack *b)
{
	t_node	*current_node;
	int		max;
	int		indice_i;
	int		i;

	current_node = b->head;
	max = INT_MIN;
	indice_i = 0;
	i = 0;
	while (current_node)
	{
		if (current_node->value >= max)
		{
			max = current_node->value;
			indice_i = i;
		}
		current_node = current_node->next;
		i++;
	}
	if (indice_i > b->size / 2)
		indice_i -= b->size;
	return (indice_i);
}

void	ft_sort_b(t_stack *a, t_stack *b, t_log *log)
{
	int	next;

	while (b->size > 0)
	{
		next = find_max(b);
		if (next > 0)
			while (next-- > 0)
				ft_rotate_b(b, log);
		else if (next < 0)
			while (next++ < 0)
				ft_reverse_rotate_b(b, log);
		ft_push_a(a, b, log);
	}
}

static void	ft_rank(t_stack *a)
{
	t_node	*node;
	int		smallest;
	int		i;

	i = 0;
	node = a->head;
	while (i < a->size)
	{
		node = a->head;
		smallest = INT_MAX;
		while (node)
		{
			if (node->value < smallest && node->value >= INT_MIN + i)
				smallest = node->value;
			node = node->next;
		}
		node = a->head;
		while (node->value != smallest)
			node = node->next;
		node->value = INT_MIN + i;
		i++;
	}
}

int	ft_sqrt_round_up(int nb)
{
	int	left;
	int	right;
	int	mid;

	if (nb <= 0)
		return (0);
	left = 1;
	right = nb;
	while (left < right)
	{
		mid = left + (right - left) / 2;
		if ((long)mid * mid >= nb)
			right = mid;
		else
			left = mid + 1;
	}
	return (left);
}

int	ft_bucket(t_stack *a, t_stack *b, t_log *log)
{
	int	current;

	ft_rank(a);
	current = INT_MIN + ft_sqrt_round_up(a->size);
	while (a->size > 0)
	{
		if ((a->head->value) <= current)
		{
			ft_push_b(a, b, log);
			if (current % 2 == 0)
				ft_rotate_b(b, log);
			current++;
		}
		else
			ft_rotate_a(a, log);
	}
	ft_sort_b(a, b, log);
	return (1);
}
