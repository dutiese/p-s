/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:47 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:23:39 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	set_len;
	size_t	len;

	if (!s1)
		return (NULL);
	set_len = ft_strlen(set);
	while (*s1)
	{
		if (ft_memchr(set, *s1, set_len) == 0)
			break ;
		s1++;
	}
	len = ft_strlen(s1);
	while (len > 0)
	{
		if (ft_memchr(set, s1[len - 1], set_len) == 0)
			break ;
		len--;
	}
	return (ft_substr(s1, 0, len));
}
