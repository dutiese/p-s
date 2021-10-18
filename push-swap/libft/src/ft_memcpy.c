/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:58 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:22:52 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*dest;
	unsigned char		*serc;
	size_t				i;

	dest = (unsigned char *)dst;
	serc = (unsigned char *)src;
	i = 0;
	if (!n || dest == serc)
		return (dest);
	while (n > i)
	{
		dest[i] = serc[i];
		i++;
	}
	return (dest);
}
