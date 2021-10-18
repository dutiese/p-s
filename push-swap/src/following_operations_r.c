/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   following_operations_r.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/12 17:30:42 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/16 14:31:19 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_ra(t_stack **a, int status)
{
	t_stack	*lstfirst;
	t_stack	*lstmove;
	t_stack	*lstlast;

	if (!*a || !(*a)->next)
		return ;
	lstmove = *a;
	lstfirst = (*a)->next;
	lstlast = *a;
	while (lstlast->next != NULL)
		lstlast = lstlast->next;
	lstmove->next = NULL;
	lstlast->next = lstmove;
	*a = lstfirst;
	if (status == 1)
		write(1, "ra\n", 3);
}

void	ft_rra(t_stack **a, int status)
{
	t_stack	*lstfirst;
	t_stack	*lstmove;
	t_stack	*before_lstlast;

	if (!*a || !(*a)->next)
		return ;
	lstfirst = *a;
	before_lstlast = *a;
	while (before_lstlast->next->next != NULL)
		before_lstlast = before_lstlast->next;
	lstmove = before_lstlast->next;
	before_lstlast->next = NULL;
	lstmove->next = lstfirst;
	*a = lstmove;
	if (status == 1)
		write(1, "rra\n", 4);
}

void	ft_rb(t_stack **b, int status)
{
	t_stack	*lstfirst;
	t_stack	*lstmove;
	t_stack	*lstlast;

	if (!*b || !(*b)->next)
		return ;
	lstmove = *b;
	lstfirst = (*b)->next;
	lstlast = *b;
	while (lstlast->next != NULL)
		lstlast = lstlast->next;
	lstmove->next = NULL;
	lstlast->next = lstmove;
	*b = lstfirst;
	if (status == 1)
		write(1, "rb\n", 3);
}

void	ft_rrb(t_stack **b, int status)
{
	t_stack	*lstfirst;
	t_stack	*lstmove;
	t_stack	*before_lstlast;

	if (!(*b) || !(*b)->next)
		return ;
	lstfirst = *b;
	before_lstlast = *b;
	while (before_lstlast->next->next != NULL)
		before_lstlast = before_lstlast->next;
	lstmove = before_lstlast->next;
	before_lstlast->next = NULL;
	lstmove->next = lstfirst;
	*b = lstmove;
	if (status == 1)
		write(1, "rrb\n", 4);
}
