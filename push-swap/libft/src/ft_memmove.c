/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:01 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:22:55 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*dest;
	unsigned char		*serc;
	size_t				i;

	dest = (unsigned char *)dst;
	serc = (unsigned char *)src;
	i = 0;
	if (!dest && !serc)
		return (0);
	if (dest > serc)
	{
		while (len-- > 0)
			dest[len] = serc[len];
	}
	else
	{
		while (i < len)
		{
			dest[i] = serc[i];
			i++;
		}
	}
	return (dest);
}
