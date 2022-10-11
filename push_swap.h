/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:13:09 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/11 16:15:26 by hmorales         ###   ########.fr       */
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
void	print_stack(t_list *a);
int		is_sorted(int mid, t_list *a);
void	parse(char *str);
void	sort_2(t_list **a, t_list **b);
int		stack_len(t_list *a);

#endif
