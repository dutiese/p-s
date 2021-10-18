/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   following_operations_s.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:30:51 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/12 17:31:58 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_sa(t_stack *a, int status)
{
	int	tmp;

	if (a == 0 || a->next == 0)
		return ;
	tmp = a->value;
	a->value = a->next->value;
	a->next->value = tmp;
	if (status == 1)
		write(1, "sa\n", 3);
}

void	ft_sb(t_stack *b, int status)
{
	int	tmp;

	if (b == 0 || b->next == 0)
		return ;
	tmp = b->value;
	b->value = b->next->value;
	b->next->value = tmp;
	if (status == 1)
		write(1, "sb\n", 3);
}

void	ft_ss(t_stacks *s, int status)
{
	ft_sa(s->a, 0);
	ft_sb(s->b, 0);
	if (status == 1)
		write(1, "ss\n", 3);
}
