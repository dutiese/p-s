/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   before_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:54:37 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 17:54:37 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_where(t_stacks *s, t_stack *b, int *activity, int *tmp)
{
	while (s->a)
	{
		*tmp = s->a->value;
		if (b->value > s->a->value)
		{
			*activity += 1;
			if (b->value < s->a->next->value)
				break ;
			s->a = s->a->next;
		}
		else
			break ;
	}
	if (ft_find_small(s->a, *tmp, b->value) == 1)
	{
		while (s->a)
		{
			if (s->a->value < *tmp && s->a->value > b->value)
				break ;
			*activity += 1;
			s->a = s->a->next;
		}
	}
}

int	ft_where_is(t_stacks *s, t_stack *b, t_steps *steps, int min)
{
	int	activity;
	int	r;
	int	tmp;

	activity = 0;
	tmp = 0;
	ft_where(s, b, &activity, &tmp);
	if (s->a->rotate == -1)
		activity = s->len_a - activity;
	if (min == -1 || (activity + b->go) < min)
	{
		steps->dest_a = s->a->rotate;
		steps->dest_b = b->rotate;
		steps->len_a = activity;
		steps->len_b = b->go;
		r = activity + b->go;
	}
	else
		r = min;
	return (r);
}

int	ft_find_small(t_stack *a, int tmp, int src)
{
	t_stack	*to_save;
	int		ret;

	to_save = a;
	ret = 0;
	while (to_save && ret == 0)
	{
		if (to_save->value < tmp && to_save->value > src)
			ret = 1;
		to_save = to_save->next;
	}
	return (ret);
}

int	ft_rem_min(t_stack *a, int min)
{
	int	i;

	i = 0;
	while (a)
	{
		if (a->value == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
