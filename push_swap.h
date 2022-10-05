/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:13:09 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 16:39:58 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include "libft/libft.h"

typedef struct stack
{
	int	num;
}	t_stack;

void	initializer(int argc, char **argv, t_list **a, t_list **copy);
void	swap(t_list *a);
void	push(t_list **pushed, t_list *put);
void	rotate(t_list *a);
void	rev_rotate(t_list *a);
void	process(t_list **a, t_list **b);
int		sorted(t_list *a);
void	print_stack(t_list *a);

#endif
