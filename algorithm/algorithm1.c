/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:50:27 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/17 13:07:35 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	cycle_a(t_list **a, int num)
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

void	cycle_b(t_list **b, int num)
{
	int	i;

	i = ft_abs(num);
	while (i > 0)
	{
		if (num < 0)
			rev_rotate(b, "rrb\n");
		else
			rotate(b, "rb\n");
		i--;
	}
}

void	find_waldo(t_list **a, t_list **b, int num)
{
	int	fw;
	int	bw;

	fw = position_list_fw(*b, num, num);
	bw = position_list_bw(*b, num, num);
	if (ft_abs(fw) > ft_abs(bw))
	{
		cycle_b(b, bw);
		push(a, b, "pb\n");
	}
	else
	{
		cycle_b(b, fw);
		push(a, b, "pb\n");
	}
}

void	analyze_b(t_list **b, t_list **a)
{
	int	num_a;
	int	num_b;
	int	desired;
	
	num_a = ((t_stack *)(*a)->content)->num;
	desired = find_min(*b);
	while((*b)->next)
	{
		num_b = ((t_stack *)(*b)->content)->num;
		if ((num_b < num_a) && (num_b > desired))
			desired = num_b;
		*b = (*b)->next;
	}
	*b = ft_lstfirst(*b);
	if (desired > num_a)
	{
		push(a, b, "pb\n");
		rotate(b, "rb\n");
	}
	else
		find_waldo(a, b, desired);
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
				cycle_a(a, position_list_bw(*a, fst, lst));
			else
				cycle_a(a, position_list_fw(*a, fst, lst));
			if (ft_lstsize(*b) >= 2)
			{
				if (((t_stack *)(*b)->content)->num < ((t_stack *)(*b)->next->content)->num)
					swap(b, "sb\n");
				analyze_b(b, a);
			}
			else
				push(a, b, "pb\n");
			print_stacks(*a, *b);
			i--;
		}
		i = og;
		fst = fst + og;
		lst = lst + og;
	}
}

