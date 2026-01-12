/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 09:44:31 by mthetcha          #+#    #+#             */
/*   Updated: 2026/01/12 23:46:13 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	handle_flag(t_stack *a, t_stack *b, int flag, t_log *log)
{
	if (flag % 4 == 1)
		return (ft_seletion(a, b, log));
	else if (flag % 4 == 2)
		return (ft_bucket(a, b, log));
	else if (flag % 4 == 3)
		return (ft_radix(a, b, log));
	if (((1 - compute_disorder(a)) * a->size) > 20)
		return (ft_radix(a, b, log));
	else
		return (ft_seletion(a, b, log));
}

static int	ft_sort_stack(t_stack *a, t_stack *b, int flag)
{
	t_log	log;
	double	cp_disorder;

	cp_disorder = compute_disorder(a);
	log = ft_init_log();
	if (cp_disorder < 0)
		return (-1);
	if (cp_disorder != 1 && handle_flag(a, b, flag, &log) == -1)
		return (-1);
	if (flag & (1 << 2))
		ft_print_bench(cp_disorder, flag, &log, a->size);
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		flag;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	flag = 0;
	i = 1;
	while (i < argc && get_flag(argv[i], &flag))
		i++;
	a = init_stack();
	b = init_stack();
	if ((create_strack(&a, i, argc, argv) == -1)
		|| ft_sort_stack(&a, &b, flag) == -1)
		return (ft_exit_on_error());
	return (0);
}
