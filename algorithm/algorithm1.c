/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 11:50:27 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/18 16:52:21 by hmorales         ###   ########.fr       */
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

void	find_waldo(t_list **b, int num)
{
	int	fw;
	int	bw;

	fw = position_list_fw(*b, num, num);
	bw = position_list_bw(*b, num, num);
	if (ft_abs(fw) > ft_abs(bw))
		cycle_b(b, bw);
	else
		cycle_b(b, fw);
}

void	analyze_b(t_list **b, t_list **a)
{
	int	num_a;
	int	num_b;
	int	desired;

	num_a = ((t_stack *)(*a)->content)->num;
	desired = find_min(*b);
	while ((*b)->next)
	{
		num_b = ((t_stack *)(*b)->content)->num;
		if ((num_b < num_a) && (num_b > desired))
			desired = num_b;
		*b = (*b)->next;
	}
	*b = ft_lstfirst(*b);
	if (((t_stack *)(*b)->content)->num < \
	((t_stack *)(*b)->next->content)->num)
		swap(b, "sb\n");
	if (ft_lstsize(*b) > 3)
		find_waldo(b, desired);
	push(a, b, "pb\n");
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
			curator(a, b, fst, lst);
			i--;
		}
		absurd_math(&fst, &lst, &i, og);
		if (lst > j)
		{
			i = ft_lstsize(*a) % div;
			lst = j;
		}
	}
}
