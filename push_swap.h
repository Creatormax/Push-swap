/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:13:09 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/18 16:50:36 by hmorales         ###   ########.fr       */
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
void	swap(t_list **a, char *op);
void	push(t_list **src, t_list **dest, char *op);
void	rotate(t_list **a, char *op);
void	rev_rotate(t_list **a, char *op);
void	print_stacks(t_list *a, t_list *b);
int		is_sorted(int mid, t_list *a);
void	parse(char *str);
void	process(t_list **a, t_list **b);
int		find_max(t_list *a);
int		find_min(t_list *a);
int		position_list_fw(t_list *a, int ni, int nf);
int		position_list_bw(t_list *a, int ni, int nf);
t_list	*b_not_included(t_list *b);
void	sort100(t_list **a, t_list **b, int div);
void	sort2(t_list **a);
void	analyze_b(t_list **b, t_list **a);
void	sort_check(t_list **a, t_list **b);
void	cycle_b(t_list **b, int num);
void	cycle_a(t_list **a, int num);
void	curator(t_list **a, t_list **b, int fst, int lst);
void	absurd_math(int *fst, int *lst, int *i, int og);

#endif
