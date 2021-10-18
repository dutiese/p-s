/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:50:03 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/10 15:21:47 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static int	ft_minint(long int res)
{
	res = INT_MIN;
	return (res);
}

static int	ft_overlongvalue(int sign)
{
	if (sign == -1)
		return (0);
	return (-1);
}

static int	ft_isspase(int c)
{
	return (c == ' ' || c == '\n' || c == '\t' || c == '\v'
		|| c == '\f' || c == '\r');
}

int	ft_res( int res, const char *str, int i)
{
	int	sign;

	sign = 1;
	while (ft_isspase(str[i]))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (res - 1 > INT_MAX)
			return (ft_overlongvalue(sign));
		res = res * 10 + (str[i++] - 48);
	}
	return (res * sign);
}

int	ft_atoi(const char *str)
{
	long int	res;
	int			i;

	i = 0;
	res = 0;
	if (!(ft_strncmp(str, "-2147483648", 11)))
		return (ft_minint(res));
	while (str[i])
		return (ft_res(res, str, i));
	return (0);
}
