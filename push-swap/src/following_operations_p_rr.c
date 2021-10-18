/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   following_operations_p_rr.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:30:38 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/16 16:05:50 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_pa(t_stacks *s, int status)
{
	t_stack	*tmp;

	if (!s->b)
		return ;
	s->len_a += 1;
	s->len_b -= 1;
	tmp = s->b;
	s->b = s->b->next;
	tmp->next = s->a;
	s->a = tmp;
	if (status == 1)
		write(1, "pa\n", 3);
}

void	ft_pb(t_stacks *s, int status)
{
	t_stack	*tmp;

	s->len_a -= 1;
	s->len_b += 1;
	tmp = s->a;
	s->a = s->a->next;
	tmp->next = s->b;
	s->b = tmp;
	if (status == 1)
		write(1, "pb\n", 3);
}

void	ft_rrr(t_stacks *s, int status)
{
	ft_rra(&s->a, 0);
	ft_rrb(&s->b, 0);
	if (status == 1)
		write(1, "rrr\n", 4);
}

void	ft_rr(t_stacks *s, int status)
{
	ft_ra(&s->a, 0);
	ft_rb(&s->b, 0);
	if (status == 1)
		write(1, "rr\n", 3);
}
