/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:06:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/17 10:23:14 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdint.h>
# include <stdbool.h>

typedef struct s_clist
{
	int				content;
	int				rank;
	int				r_index;
	int				rr_index;
	int				price;
	struct s_clist	*next;
	struct s_clist	*previous;
}	t_clist;

//list
t_clist	*ft_circ_lstnew(int content, int rank);
void	ft_circ_lstadd_front(t_clist **lst, t_clist *new);
void	ft_circ_lstdelone(t_clist **lst);
void	ft_circ_lstclear(t_clist **lst);
int		ft_circ_lstsize(t_clist **lst);

//checks & parsing
bool	is_valid_input(int count, char **input);
bool	is_sorted(t_clist **stack);
void	get_ranks(int count, char **params, int *numbers, int *ranks);
t_clist	**create_stack(int count, char **params);

//utils
int		min(int count, ...);
int		max(int count, ...);
char	**stack_to_heap(char **stack_array, int size);
int		number_count(char const *str, char c);
//utils2
void	ft_free(void **p);
void	array_free(char ***arr);
void	malloc_failed(t_clist **stack_a, char **arr, void *p1, void *p2);

//operations
void	swap(t_clist **stack);
void	push(t_clist **stack_src, t_clist **stack_dest);
void	rotate(t_clist **head, bool is_reverse);
void	exec_rule(t_clist **s_a, t_clist **s_b, char *rule, bool is_bonus);
void	repeat_rule(t_clist **a, t_clist **b, int times, char *rule);

//sorting
	//main
void	mini_sort(t_clist **a);
int		sort(t_clist	**stack_a, int count);
	//sort utils
void	set_rotate_index(t_clist **stack, int count);
void	set_price(t_clist *node_a, t_clist *node_b);
void	rotate_to_push(t_clist **a, t_clist **b, t_clist *n_a, t_clist *n_b);
	//sort part1
t_clist	*where_to_fit_in_b(int rank, t_clist **b, int minimum, int maximum);
void	rotate_to_pb(t_clist **a, t_clist **b, int minimum, int maximum);
void	sort_push_b(t_clist **a, t_clist **b, int count);
	//sort part2
t_clist	*where_to_fit_in_a(int rank, t_clist **a, int minimum, int maximum);
void	rotate_to_pa(t_clist **a, t_clist **b, int minimum, int maximum);
void	final_sort(t_clist **a, int minimum, int maximum);
void	sort_push_a(t_clist **a, t_clist **b, int count);

#endif
