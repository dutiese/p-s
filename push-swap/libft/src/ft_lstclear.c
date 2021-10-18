/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:34 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:22:21 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buf;

	if (!lst)
		return ;
	while (*lst)
	{
		del((*lst)->content);
		buf = *lst;
		*lst = buf->next;
		free(buf);
	}
	(*lst) = NULL;
}
