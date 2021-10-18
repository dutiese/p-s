/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dutiese <dutiese@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 16:55:00 by dutiese           #+#    #+#             */
/*   Updated: 2021/10/18 20:43:25 by dutiese          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/inc/libft.h"

typedef struct s_stack
{
	int				value;
	int				go;
	int				rotate;
	struct s_stack	*next;
}					t_stack;

typedef struct s_value
{
	int				a[10000];
	int				elements;
}					t_value;

typedef struct s_steps
{
	int				len_a;
	int				len_b;
	int				dest_a;
	int				dest_b;
}					t_steps;

typedef struct s_stacks
{
	t_stack			*a;
	t_stack			*b;
	int				len_a;
	int				len_b;
	int				min;
	int				medium;
	int				max;
}					t_stacks;

void	ft_sa(t_stack *a, int status);
void	ft_sb(t_stack *b, int status);
void	ft_ss(t_stacks *s, int status);
void	ft_pa(t_stacks *s, int status);
void	ft_pb(t_stacks *s, int status);
void	ft_rr(t_stacks *s, int status);
void	ft_ra(t_stack **a, int status);
void	ft_rra(t_stack **a, int status);
void	ft_rb(t_stack **b, int status);
void	ft_rrb(t_stack **b, int status);
int		ft_sorted(t_value *new);
int		ft_space(const char *str);
void	ft_dup_search(const int *dups, int count);
void	ft_check_dup(t_value*new, t_stacks *s);
void	ft_str(const char *str);
void	ft_acsess_nbrs(const char *str);
int		ft_valid(int argc, char **argv);
char	**ft_ssplit(char const *s, int word);
void	ft_separ(int argc, char **argv, t_value *new);
void	ft_stacks(t_value *new, int *buff, int count);
t_stack	*ft_create_s(const int *tmp, int count);
void	ft_clear_and_free(t_stacks *s);
void	ft_null(t_stacks *s, t_value *elem);
void	ft_init_s(t_value *born, t_stacks *s);
void	ft_what_sort(t_stacks *s);
void	ft_3_elem(t_stacks *s);
void	ft_5_elem(t_stacks *s);
int		ft_max(t_stack *s);
int		ft_section(int *array, int start, int end);
void	ft_sort(int *array, int end, int start);
void	ft_mega_sort(t_stacks *stacks);
void	ft_min_steps(t_stacks *s, t_steps *go);
void	ft_marking(t_stack *b, int count);
void	ft_plan(t_stacks *s, t_steps *go);
void	ft_begin(t_stacks *s);
int		ft_rem_min(t_stack *a, int min);
int		ft_find_small(t_stack *a, int tmp, int src);
int		ft_where_is(t_stacks *s, t_stack *b, t_steps *steps, int min);
void	ft_where(t_stacks *s, t_stack *b, int *activity, int *tmp);
int		*ft_intcpy(int *dst, const int *src, int count);
void	ft_rewrite(char const *s, char **mass);
int		ft_word_malloc(char const *s, char **mass);
int		ft_quantity_elems(char const *str);
int		check_stack_a(t_stack *ab);

#endif
