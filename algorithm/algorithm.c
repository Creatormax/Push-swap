/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:38 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/17 12:29:16 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort3_1(t_list **a, int min)
{
	if (((t_stack *)(*a)->content)->num == min)
	{
		swap(a, "sa\n");
		rotate(a, "ra\n");
	}
	else
		rev_rotate(a, "rra\n");
}

void	sort3(t_list **a, int max, int min)
{
	if ((((t_stack *)(*a)->content)->num != min) && \
	(((t_stack *)(*a)->next->next->content)->num != max))
	{
		if (((t_stack *)(*a)->next->content)->num == min)
		{
			if (((t_stack *)(*a)->content)->num == max)
				rotate(a, "ra\n");
			else
				swap(a, "sa\n");
		}
		else if (((t_stack *)(*a)->next->content)->num == max)
			sort3_1(a, min);
		else
		{
			swap(a, "sa\n");
			rev_rotate(a, "rra\n");
		}
	}
}

void	sort5(t_list **a, t_list **b, int max, int min)
{
	int	i;

	i = 0;
	while (i < 2)
	{
		if (((t_stack *)(*a)->content)->num == max || \
		((t_stack *)(*a)->content)->num == min)
		{
			push(a, b, "pb\n");
			i++;
		}
		else
			rotate(a, "ra\n");
	}
	sort3(a, find_max(*a), find_min(*a));
	if (((t_stack *)(*b)->content)->num < ((t_stack *)(*b)->next->content)->num)
		push(b, a, "pa\n");
	else
	{
		rotate(b, "rb\n");
		push(b, a, "pa\n");
	}
	push(b, a, "pa\n");
	rotate(a, "ra\n");
}

void	sort2(t_list **a)
{
	if (((t_stack *)(*a)->content)->num > ((t_stack *)(*a)->next->content)->num)
		rotate(a, "ra\n");
}

void	process(t_list **a, t_list **b)
{
	int	max;
	int	min;

	max = find_max(*a);
	min = find_min(*a);
	if (ft_lstsize(*a) == 2)
		sort2(a);
	else if (ft_lstsize(*a) == 3)
		sort3(a, max, min);
	else if (ft_lstsize(*a) == 5)
		sort5(a, b, max, min);
	else if (ft_lstsize(*a) > 5)
		sort100(a, b, 1);
	sort_check(a, b);
}
