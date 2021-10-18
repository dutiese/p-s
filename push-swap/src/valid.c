/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 19:45:15 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:26:47 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	ft_valid(int argc, char **argv)
{
	int	i;
	int	flag;

	flag = 0;
	i = 1;
	while (i < argc)
	{
		if (ft_space(argv[i]))
		{
			ft_acsess_nbrs(argv[i]);
			ft_str(argv[i]);
			flag = 1;
		}
		i++;
	}
	return (flag);
}

void	ft_acsess_nbrs(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_isdigit(str[i]))
			return ;
		i++;
	}
	ft_errorka(1);
}

void	ft_str(const char *str)
{
	size_t	i;
	int		nbr;
	int		sign;

	i = 0;
	nbr = 0;
	sign = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]))
			nbr++;
		else if (str[i] == ' ' || str[i] == '\t')
		{
			if (sign != 0 && nbr == 0)
				ft_errorka(1);
			nbr = 0;
			sign = 0;
		}
		else if (((str[i] == '+' || str[i] == '-')
				&& (sign == 0 && nbr == 0)) && (str[i + 1] != '\0'))
			sign++;
		else
			ft_errorka(1);
		i++;
	}
}

void	ft_check_dup(t_value *new, t_stacks *s)
{
	int			*dup;

	dup = (int *)malloc(sizeof(int) * (new->elements));
	if (!dup)
		ft_errorka(0);
	dup = ft_intcpy(dup, new->a, new->elements);
	ft_sort(dup, 0, new->elements - 1);
	ft_dup_search(dup, new->elements - 1);
	s->len_a = new->elements;
	s->len_b = 0;
	s->min = dup[0];
	s->medium = dup[new->elements / 2];
	s->max = dup[new->elements - 1];
	free(dup);
}

void	ft_dup_search(const int *dups, int count)
{
	int	i;

	i = 0;
	while (i != count)
	{
		if (dups[i] == dups[i + 1])
			ft_errorka(1);
		i++;
	}
}
