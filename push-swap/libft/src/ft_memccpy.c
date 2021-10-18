/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:50 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:22:44 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t				i;
	unsigned char		*dest;
	unsigned char		*serc;

	dest = (unsigned char *)dst;
	serc = (unsigned char *)src;
	i = 0;
	while (n > i)
	{
		dest[i] = serc[i];
		if (serc[i] == (unsigned char)c)
			return (&dest[++i]);
		i++;
	}
	return (0);
}
