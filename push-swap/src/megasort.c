/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megasort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:14:24 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:13:21 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_begin(t_stacks *s)
{
	t_steps	*go;

	go = (t_steps *)malloc(sizeof(t_steps));
	if (!go)
		ft_errorka(0);
	while (s->len_b != 0)
	{
		go->len_a = -1;
		go->len_b = -1;
		go->dest_a = 0;
		go->dest_b = 0;
		ft_marking(s->a, s->len_a);
		ft_marking(s->b, s->len_b);
		ft_min_steps(s, go);
		ft_plan(s, go);
	}
	if ((ft_rem_min(s->a, s->min)) > s->len_a / 2)
	{
		while (s->a->value != s->min)
			ft_rra(&s->a, 1);
	}
	else
		while (s->a->value != s->min)
			ft_ra(&s->a, 1);
	free(go);
}

void	ft_plan(t_stacks *s, t_steps *go)
{
	while (go->len_a > 0)
	{
		if (go->dest_a == 1)
			ft_ra(&s->a, 1);
		else
			ft_rra(&s->a, 1);
		go->len_a--;
	}
	while (go->len_b > 0)
	{
		if (go->dest_b == 1)
			ft_rb(&s->b, 1);
		else
			ft_rrb(&s->b, 1);
		go->len_b--;
	}
	ft_pa(s, 1);
}

void	ft_marking(t_stack *b, int count)
{
	int		i;
	int		iter;
	t_stack	*tmp;

	i = -1;
	iter = count / 2;
	tmp = b;
	while (++i <= iter)
	{
		tmp->go = i;
		tmp->rotate = 1;
		tmp = tmp->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		tmp->go = i;
		tmp->rotate = -1;
		tmp = tmp->next;
	}
}

void	ft_min_steps(t_stacks *s, t_steps *go)
{
	int		less_activity;
	t_stack	*head_a;
	t_stack	*head_b;

	less_activity = -1;
	head_a = s->a;
	head_b = s->b;
	while (s->b)
	{
		less_activity = ft_where_is(s, s->b, go, less_activity);
		s->a = head_a;
		s->b = s->b->next;
	}
	s->b = head_b;
}

void	ft_mega_sort(t_stacks *s)
{
	while (s->len_a > 2)
	{
		if (s->a->value != s->min && s->a->value != s->max)
		{
			ft_pb(s, 1);
			if (s->b->value > s->medium)
				ft_rb(&s->b, 1);
		}
		else
			ft_ra(&s->a, 1);
	}
	if (s->a->value < s->a->next->value)
		ft_sa(s->a, 1);
	ft_pa(s, 1);
	ft_begin(s);
}
