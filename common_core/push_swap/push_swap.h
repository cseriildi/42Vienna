/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/30 17:06:31 by icseri            #+#    #+#             */
/*   Updated: 2024/05/03 13:14:47 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include "libft/libft.h"
# include <stdint.h>

typedef struct s_clist
{
	void			*content;
	struct s_clist	*next;
	struct s_clist	*previous;
}	t_clist;

t_clist	*ft_circ_lstnew(void *content);
void	ft_circ_lstadd_front(t_clist **lst, t_clist *new);
void	ft_circ_lstdelone(t_clist **lst);
void	ft_circ_lstclear(t_clist **lst);

void	ft_free(char **p);
int		check_input(int count, char **input);
t_clist	**create_stack(int count, int *numbers);
int		push_swap(int count, int *numbers);

void	swap(t_clist **stack);
void	push(t_clist **stack_src, t_clist **stack_dest);
void	rotate(t_clist **head);
void	rev_rotate(t_clist **head);

#endif
