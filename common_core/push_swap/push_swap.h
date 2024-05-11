/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cseriildii <cseriildii@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:06:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/11 15:53:18 by cseriildii       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
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

//checks
bool		is_valid_input(int count, char **input);
bool		is_sorted(t_clist **stack);

//parsing
t_clist	**create_stack(int count, char **params);

//utils
void	ft_free(char **p);
int		get_min(int a, int b);
int		get_max(int a, int b);
void	print_stack(t_clist **stack);

int		sort(t_clist	**stack_a, int count);

//operations
void	swap(t_clist **stack);
void	push(t_clist **stack_src, t_clist **stack_dest);
void	rotate(t_clist **head);
void	rev_rotate(t_clist **head);
void	exec_rule(t_clist **s_a, t_clist **s_b, char *rule, bool is_bonus);

//sorting

#endif
