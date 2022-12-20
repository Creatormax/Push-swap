/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:13:09 by hmorales          #+#    #+#             */
/*   Updated: 2022/12/20 15:07:30 by hmorales         ###   ########.fr       */
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

t_list	*initializer(int argc, char **argv, t_list **a, t_list **copy);
void	swap(t_list **a);
void	push(t_list **src, t_list **dest);
void	rotate(t_list **a);
void	rev_rotate(t_list **a);
void	print_stacks(t_list *a, t_list *b);
int		is_sorted(int mid, t_list *a);
void	parse(char *str);
void	process(t_list **a, t_list **b);

#endif
