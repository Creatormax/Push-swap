/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:50:27 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/04 17:23:33 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cycle(t_list **a, int num)
{
	int	i;

	i = ft_abs(num);
	while (i > 0)
	{
		if (num < 0)
			rev_rotate(a, "rra\n");
		else
			rotate(a, "ra\n");
		i--;
	}
}

void	analyze_b(t_list **b, t_list **a)
{
	int	max;
	int	min;

	max = find_max(*b);
	if (((t_stack *)(*a)->content)->num > max)
		push(a, b, "pb\n");
	else
	{
		min = find_min(*b);
		if (((t_stack *)(*a)->content)->num < min)
		{;
			push(a, b, "pb\n");
			rotate(b, "rrb\n");
		}
		else
		{
			rev_rotate(b, "rrb\n");
			push(a, b, "pb\n");
			rotate(b, "rb\n");
			rotate(b, "rb\n");
		}
	}
	
}

void	sort100(t_list **a, t_list **b, int div)
{
	int	fst;
	int	lst;
	int	i;
	int	j;
	int	og;

	fst = find_min(*a);
	j = find_max(*a);
	i = ft_lstsize(*a) / div;
	og = i;
	lst = i + fst - 1;
	while (fst < j)
	{
		while (i > 0)
		{
			if (ft_abs(position_list_fw(*a, fst, lst)) \
			> ft_abs(position_list_bw(*a, fst, lst)))
				cycle(a, position_list_bw(*a, fst, lst));
			else
				cycle(a, position_list_fw(*a, fst, lst));
			if (ft_lstsize(*b) >= 2)
				analyze_b(b, a);
			else
				push(a, b, "pb\n");
			i--;
		}
		i = og;
		fst = fst + og;
		lst = lst + og;
	}
}

