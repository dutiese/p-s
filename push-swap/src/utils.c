/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 20:45:10 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/18 20:45:10 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_what_sort(t_stacks *s)
{
	if (s->len_a <= 3)
		ft_3_elem(s);
	else if (s->len_a <= 5)
		ft_5_elem(s);
	else
		ft_mega_sort(s);
}

int	*ft_intcpy(int *dst, const int *src, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		dst[i] = src[i];
		i++;
	}
	return (dst);
}

int	ft_quantity_elems(char const *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		if (*str != '\t' && *str != ' ')
		{
			i++;
			while ((*str != '\t' && *str != ' ') && *str)
				str++;
		}
		else
			str++;
	}
	return (i);
}

int	ft_word_malloc(char const *s, char **mass)
{
	int	lenword;
	int	i;

	i = 0;
	while (*s)
	{
		lenword = 0;
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
			{
				s++;
				lenword++;
			}
			mass[i++] = ((char *)malloc(sizeof(char) * (lenword + 1)));
			if (!mass)
				return (i);
		}
		else
			s++;
	}
	return (0);
}

void	ft_rewrite(char const *s, char **mass)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (*s)
	{
		if (*s != ' ' && *s != '\t')
		{
			while ((*s != ' ' && *s != '\t') && *s != '\0')
				mass[i][j++] = *s++;
			mass[i++][j] = '\0';
		}
		j = 0;
		if (*s != '\0')
			s++;
	}
}
