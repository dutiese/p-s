/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 15:51:19 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:21:22 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

static char	**ft_split_create(char const *s, char c)
{
	size_t			i;
	size_t			len;
	char			**array;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i == 0)
			break ;
		s = s + i;
		len++;
	}
	array = (char **)malloc(sizeof(char *) * (len + 1));
	if (!array)
		ft_errorka(0);
	return (array);
}

static char	**ft_split_make(char const *s, char c, char **array)
{
	size_t			i;
	size_t			len;

	len = 0;
	while (*s)
	{
		while (*s && *s == c)
			s++;
		i = 0;
		while (s[i] && s[i] != c)
			i++;
		if (i == 0)
			break ;
		array[len] = ft_substr(s, 0, i);
		if (!array[len])
		{
			while (len >= 0)
				free(array[--len]);
			free(array);
			return (NULL);
		}
		s = s + i;
		len++;
	}
	return (array);
}

char	**ft_split(char const *s, char c)
{
	char	**array;

	if (!s)
		return (NULL);
	array = ft_split_create(s, c);
	return (ft_split_make(s, c, array));
}
