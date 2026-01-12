/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 11:36:00 by mboutte           #+#    #+#             */
/*   Updated: 2026/01/12 23:53:18 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_common.h"

char	*get_next_line(int fd);

static int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if ((s1[i] == '\0') || (s1[i] < s2[i]))
			return (-1);
		if ((s2[i] == '\0') || (s1[i] > s2[i]))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_exec(char *str, t_stack *a, t_stack *b)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (ft_swap(a));
	else if (ft_strcmp(str, "sb\n") == 0)
		return (ft_swap(b));
	else if (ft_strcmp(str, "ss\n") == 0)
		return (ft_swap_swap(a, b));
	else if (ft_strcmp(str, "pa\n") == 0)
		return (ft_push(a, b));
	else if (ft_strcmp(str, "pb\n") == 0)
		return (ft_push(b, a));
	else if (ft_strcmp(str, "ra\n") == 0)
		return (ft_rotate(a));
	else if (ft_strcmp(str, "rb\n") == 0)
		return (ft_rotate(b));
	else if (ft_strcmp(str, "rr\n") == 0)
		return (ft_rotate_rotate(a, b));
	else if (ft_strcmp(str, "rra\n") == 0)
		return (ft_reverse_rotate(a));
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (ft_reverse_rotate(b));
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (ft_reverse_rotate_rotate(a, b));
	return (-1);
}

void	ft_list_status(t_stack *a, t_stack *b)
{
	if (compute_disorder(a) == 1 && b->size == 0)
		write(1, "\033[38;2;0;255;0m[OK]\033[0m\n", 24);
	else
		write(1, "\033[38;2;255;0;0m[KO]\033[0m\n", 24);
}

int	main(int argc, char **argv)
{
	char	*line;
	t_stack	a;
	t_stack	b;

	if (argc == 1)
		return (0);
	a = init_stack();
	b = init_stack();
	if (create_strack(&a, 1, argc, argv) == -1 || compute_disorder(&a) == -1)
		ft_exit_on_error();
	line = get_next_line(0);
	while (line)
	{
		if (ft_exec(line, &a, &b) == -1)
		{
			free(line);
			return (ft_exit_on_error());
		}
		free(line);
		line = get_next_line(0);
	}
	ft_list_status(&a, &b);
	return (0);
}
