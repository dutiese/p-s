/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:07 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:21:38 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*ss;
	size_t			i;

	ss = (unsigned char *)s;
	i = 0;
	while (n > i)
	{
		ss[i] = 0;
		i++;
	}
	return (*s);
}
