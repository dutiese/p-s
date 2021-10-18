/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:26 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:20:33 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	*ft_itoa_d(char *buf, size_t len)
{
	char		*str;
	size_t		i;

	i = 0;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		ft_errorka(0);
	while (len)
		str[i++] = buf[--len];
	str[i] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	char			buf[20];
	size_t			len;
	unsigned int	a;

	len = 0;
	if (n < 0)
		a = -n;
	else
		a = n;
	if (a == 0)
		buf[len++] = '0';
	while (a > 0)
	{
		buf[len++] = '0' + a % 10;
		a = a / 10;
	}
	if (n < 0)
		buf[len++] = '-';
	return (ft_itoa_d(buf, len));
}
