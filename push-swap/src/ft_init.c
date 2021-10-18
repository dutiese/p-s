/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:07:09 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:33:35 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

t_stack	*ft_create_s(const int *tmp, int count)
{
	int		i;
	t_stack	*str;
	t_stack	*head_a;

	i = 0;
	str = (t_stack *)malloc(sizeof(t_stack));
	if (!str)
		ft_errorka(0);
	head_a = str;
	while (i < count)
	{
		if (i < count - 1)
		{
			str->next = (t_stack *)malloc(sizeof(t_stack));
			if (!str->next)
				ft_errorka(0);
		}
		str->value = tmp[i];
		if (i == (count - 1))
			str->next = NULL;
		else
			str = str->next;
		i++;
	}
	return (head_a);
}

void	ft_clear_and_free(t_stacks *s)
{
	int		i;
	t_stack	*tmp;

	i = 0;
	while (i < s->len_a)
	{
		tmp = s->a;
		s->a = s->a->next;
		free(tmp);
		i++;
	}
	i = 0;
	while (i < s->len_b)
	{
		tmp = s->b;
		s->b = s->b->next;
		free(tmp);
		i++;
	}
}

void	ft_null(t_stacks *s, t_value *elem)
{	
	elem->elements = 0;
	s->min = 0;
	s->medium = 0;
	s->max = 0;
	s->len_a = 0;
	s->len_b = 0;
	s->a = NULL;
	s->b = NULL;
}

void	ft_init_s(t_value *born, t_stacks *s)
{
	s->a = ft_create_s(born->a, born->elements);
	s->b = NULL;
}
