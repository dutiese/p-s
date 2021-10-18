/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:45 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:23:36 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*ss;

	ss = (char *)s;
	i = ft_strlen(ss);
	while (i > 0)
	{
		if (ss[i] == (char)c)
			return (&ss[i]);
		i--;
	}
	if (i == 0)
		if (ss[i] == (char)c)
			return (&ss[i]);
	return (0);
}
