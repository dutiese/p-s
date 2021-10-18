/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push-swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/17 18:27:59 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/17 20:33:18 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_value		*new;
	t_stacks	*s;

	if (argc < 2)
		ft_errorka(1);
	new = (t_value *)malloc(sizeof(t_value));
	s = (t_stacks *)malloc(sizeof(t_stacks));
	if (!s || !new)
		ft_errorka(0);
	ft_null(s, new);
	if (ft_valid(argc, argv))
	{
		ft_separ(argc, argv, new);
		ft_check_dup(new, s);
		if (ft_sorted(new))
		{
			ft_init_s(new, s);
			ft_what_sort(s);
			ft_clear_and_free(s);
		}
	}
	free(new);
	free(s);
	return (0);
}
