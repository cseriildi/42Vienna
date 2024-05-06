/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:06:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/06 11:09:39 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include "ft_printf/ft_printf.h"
# include <stdint.h>

typedef struct s_clist
{
	int			content;
	int			rank;
	struct s_clist	*next;
	struct s_clist	*previous;
}	t_clist;

//list
t_clist	*ft_circ_lstnew(int content, int rank);
void	ft_circ_lstadd_front(t_clist **lst, t_clist *new);
void	ft_circ_lstdelone(t_clist **lst);
void	ft_circ_lstclear(t_clist **lst);

//push_swap
void	ft_free(char **p);
int		check_input(int count, char **input);
t_clist	**create_stack(int count, char **params);
int		push_swap(t_clist	**stack_a);

//operations
void	swap(t_clist **stack);
void	push(t_clist **stack_src, t_clist **stack_dest);
void	rotate(t_clist **head);
void	rev_rotate(t_clist **head);

//sorting
int		check_if_sorted(t_clist **stack, int direction);
void	sorting(t_clist **stack_a, t_clist **stack_b, char *rule);


void	print_stack(t_clist **stack);
#endif
