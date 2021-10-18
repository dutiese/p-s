/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   separ.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:34:22 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:38:24 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	ft_separ(int argc, char **argv, t_value *new)
{
	char	**array;
	int		p;
	int		i;
	int		*bf;
	int		quantity;

	i = 1;
	while (i < argc)
	{
		p = -1;
		quantity = ft_quantity_elems(argv[i]);
		bf = (int *)malloc(sizeof(int) * (quantity));
		if (!bf)
			ft_errorka(0);
		array = ft_ssplit(argv[i], quantity);
		while (quantity > ++p)
		{
			bf[p] = ft_atoi(array[p]);
			free(array[p]);
		}
		free(array);
		ft_stacks(new, bf, quantity);
		i++;
	}
}

void	ft_stacks(t_value *new, int *buff, int count)
{
	int	i;

	i = -1;
	while (count > ++i)
		new->a[new->elements + i] = buff[i];
	new->elements += count;
	free(buff);
}

char	**ft_ssplit(char const *s, int word)
{
	char	**ar;
	int		res;

	if (!s)
		return (NULL);
	ar = (char **)malloc(sizeof(char *) * (word + 1));
	if (!ar)
		ft_errorka(0);
	ar[word] = NULL;
	res = ft_word_malloc(s, ar);
	if (res == 0)
		ft_rewrite(s, ar);
	else
	{
		while (res != 0)
		{
			free(ar[res]);
			ar[res--] = NULL;
		}
		free(ar);
	}
	return ((char **)ar);
}

int	ft_space(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n' || str[i] == '\t' || str[i] == '\v'
			|| str[i] == ' ' || str[i] == '\r' || str[i] == '\f')
			i++;
		else
			return (1);
	}
	return (0);
}

int	ft_sorted(t_value *new)
{
	int	i;

	i = 0;
	while (i < (new->elements - 1))
	{
		if (new->a[i] > new->a[i + 1])
			return (1);
		i++;
	}
	return (0);
}
