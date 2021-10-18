/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_5_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 17:50:43 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:17:17 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_3_elem(t_stacks *s)
{
	int	max;

	max = ft_max(s->a);
	if (s->len_a == 1)
		return ;
	else if (s->len_a == 2)
	{
		if (s->a->value > s->a->next->value)
			ft_sa(s->a, 1);
		return ;
	}
	else if (s->len_a == 3)
	{
		if (s->a->value == max)
			ft_ra(&s->a, 1);
		if (s->a->next->value == max)
			ft_rra(&s->a, 1);
		if (s->a->value > s->a->next->value)
			ft_sa(s->a, 1);
	}
}

void	ft_5_elem(t_stacks *s)
{
	while (s->len_b < 2)
	{
		if (s->a->value == s->min || s->a->value == s->max)
			ft_pb(s, 1);
		else
			ft_ra(&s->a, 1);
	}
	ft_3_elem(s);
	ft_pa(s, 1);
	ft_pa(s, 1);
	if (s->a->value == s->max)
	{
		ft_ra(&s->a, 1);
	}
	else
	{
		ft_sa(s->a, 1);
		ft_ra(&s->a, 1);
	}
}

int	ft_max(t_stack *s)
{
	int	max;

	max = s->value;
	while (s)
	{
		if (s->value > max)
			max = s->value;
		s = s->next;
	}
	return (max);
}

void	ft_sort(int *array, int end, int start)
{
	int	i;

	if (start < end)
	{
		i = ft_section(array, start, end);
		ft_sort(array, start, i - 1);
		ft_sort(array, i + 1, end);
	}
}

int	ft_section(int *array, int start, int end)
{
	int	j;
	int	i;
	int	tmp;
	int	end_ar;

	end_ar = array[end];
	i = start - 1;
	j = start;
	while (j < end)
	{
		if (array[j] <= end_ar)
		{
			i++;
			tmp = array[i];
			array[i] = array[j];
			array[j] = tmp;
		}
		j++;
	}
	tmp = array[i + 1];
	array[i + 1] = array[end];
	array[end] = tmp;
	return (i + 1);
}
