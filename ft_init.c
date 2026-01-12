/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/10 17:05:04 by mboutte           #+#    #+#             */
/*   Updated: 2026/01/12 23:44:08 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	init_stack(void)
{
	t_stack	stack;

	stack.head = NULL;
	stack.tails = NULL;
	stack.size = 0;
	return (stack);
}

t_log	ft_init_log(void)
{
	t_log	log;

	log.sa = 0;
	log.sb = 0;
	log.ss = 0;
	log.pa = 0;
	log.pb = 0;
	log.ra = 0;
	log.rb = 0;
	log.rr = 0;
	log.rra = 0;
	log.rrb = 0;
	log.rrr = 0;
	return (log);
}
