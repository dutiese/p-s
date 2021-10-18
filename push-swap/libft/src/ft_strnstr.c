/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:42 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:23:34 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (needle && needle[i] == '\0')
		return ((char *)haystack);
	while (len > i && haystack[i])
	{
		while (haystack[i] == needle[j] && len > i)
		{
			i++;
			j++;
			if (needle[j] == '\0')
				return ((char *)haystack + i - j);
		}
		i = i - j + 1;
		j = 0;
	}
	return (0);
}
