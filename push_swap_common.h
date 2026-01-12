/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_common.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mboutte <mboutte@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/19 10:58:55 by mboutte           #+#    #+#             */
/*   Updated: 2026/01/13 00:01:16 by mboutte          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_COMMON_H
# define PUSH_SWAP_COMMON_H

# include <unistd.h>
# include <limits.h>

# include <stdlib.h>

typedef struct s_stack
{
	struct s_node	*head;
	struct s_node	*tails;
	int				size;
}	t_stack;

typedef struct s_node
{
	int				value;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

int		ft_swap(t_stack *stack);
int		ft_swap_swap(t_stack *a, t_stack *b);
int		ft_push(t_stack *stack_target, t_stack *stack_node);
int		ft_rotate(t_stack *stack);
int		ft_rotate_rotate(t_stack *a, t_stack *b);
int		ft_reverse_rotate(t_stack *stack);
int		ft_reverse_rotate_rotate(t_stack *a, t_stack *b);

t_stack	init_stack(void);
int		ft_strlen_secure(char *str);

int		ft_exit_on_error(void);
double	compute_disorder(t_stack *stack);

int		create_strack(t_stack *a, int i, int ac, char **av);

#endif