/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:46:58 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/18 17:38:12 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	max_first(t_list **b)
{
	int	max;

	max = find_max(*b);
	if (ft_abs(position_list_fw(*b, max, max)) \
	> ft_abs(position_list_bw(*b, max, max)))
		cycle_b(b, position_list_bw(*b, max, max));
	else
		cycle_b(b, position_list_fw(*b, max, max));
}

int	existance(t_list *b, int num)
{
	int	size;
	int	i;
	int	num_b;

	i = 0;
	size = ft_lstsize(b);
	while (i < size)
	{
		num_b = ((t_stack *)(b)->content)->num;
		if (num == num_b)
			return (1);
		i++;
		b = b->next;
	}
	return (0);
}

void	sort_check(t_list **a, t_list **b)
{
	int	i;
	int	size;
	int	max;

	i = 0;
	max_first(b);
	size = ft_lstsize(*b);
	max = ((t_stack *)(*b)->content)->num;
	while (size > i)
	{
		while (((t_stack *)(*b)->content)->num != max)
		{
			while (existance(*b, max) == 0)
				max--;
			if (ft_abs(position_list_fw(*b, max, max)) \
			> ft_abs(position_list_bw(*b, max, max)))
				cycle_b(b, position_list_bw(*b, max, max));
			else
				cycle_b(b, position_list_fw(*b, max, max));
		}
		push(b, a, "pa\n");
		max--;
		i++;
	}
}

void	curator(t_list **a, t_list **b, int fst, int lst)
{
	if (ft_abs(position_list_fw(*a, fst, lst)) \
	> ft_abs(position_list_bw(*a, fst, lst)))
		cycle_a(a, position_list_bw(*a, fst, lst));
	else
		cycle_a(a, position_list_fw(*a, fst, lst));
	if (ft_lstsize(*b) >= 2)
		analyze_b(b, a);
	else
		push(a, b, "pb\n");
}

void	absurd_math(int *fst, int *lst, int *i, int og)
{
	*fst = *fst + og;
	*i = og;
	*lst = *lst + og;
}
