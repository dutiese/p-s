/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:28 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:22:02 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*buf;
	size_t	n;
	size_t	m;

	if (!s1 || !s2)
		return (NULL);
	n = ft_strlen(s1);
	m = ft_strlen(s2);
	buf = (char *)malloc(sizeof(char) * (n + m + 1));
	if (!buf)
		ft_errorka(0);
	ft_memcpy(buf, s1, n);
	ft_memcpy(buf + n, s2, m);
	buf[n + m] = '\0';
	return (buf);
}
