/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:25 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:21:42 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*buf;

	len = ft_strlen(s1);
	buf = (char *)malloc(sizeof(char) * (len + 1));
	if (!buf)
		ft_errorka(0);
	return (ft_memcpy(buf, s1, len + 1));
}
