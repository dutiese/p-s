/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:49 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:22:41 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*buf;
	size_t	n;
	size_t	need_len;

	if (!s)
		return (NULL);
	need_len = len;
	n = ft_strlen(s);
	if (n - start < len)
		need_len = n - start;
	if (start >= n || len <= 0)
		return (ft_strdup(""));
	buf = (char *)malloc(sizeof(char) * (need_len + 1));
	if (!buf)
		ft_errorka(0);
	if (start + need_len > n)
		need_len = n - start;
	if (need_len > 0)
		ft_memcpy(buf, s + start, need_len);
	buf[need_len] = '\0';
	return (buf);
}
