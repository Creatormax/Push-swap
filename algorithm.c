/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:01:38 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/03 14:58:07 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_list **a)
{
	if ((((t_stack *)(*a)->content)->num != find_min(*a)) && \
	(((t_stack *)(*a)->next->next->content)->num != find_min(*a)))
	{
		if (((t_stack *)(*a)->next->content)->num == find_min(*a))
		{
			if (((t_stack *)(*a)->content)->num == find_max(*a))
				rotate(a, "ra\n");
			else
				swap(a, "sa\n");
		}
		else if (((t_stack *)(*a)->next->content)->num == find_max(*a))
		{
			if (((t_stack *)(*a)->content)->num == find_min(*a))
			{
				swap(a, "sa\n");
				rotate(a, "ra\n");
			}
			else
				rev_rotate(a, "rra\n");
		}
		else
		{
			swap(a, "sa\n");
			rev_rotate(a, "rra\n");
		}
	}
}

void	sort5(t_list **a, t_list **b, int max, int min)
{
	int i;

	i = 0;
	while (i < 2)
	{
		if (max == ((t_stack *)(*a)->content)->num)
		{
			push(a, b, "pb\n");
			i++;
		}
		if (min == ((t_stack *)(*a)->content)->num)
		{
			push(a, b, "pb\n");
			i++;
		}
		rotate(a, "ra\n");
	}
	print_stacks(*a, *b);
	sort3(a);
	if (((t_stack *)(*b)->content)->num > ((t_stack *)(*b)->next->content)->num)
		push(b, a, "pa\n");
	else
	{
		rotate(b, "rb\n");
		push(b, a, "pa\n");
	}
	push(b, a, "pa\n");
}

void	process(t_list **a, t_list **b)
{
	int	max;
	int	min;

	max = find_max(*a);
	min = find_min(*a);
	printf("\n%d %d\n", min, max);
	sort5(a, b, max, min);
	print_stacks(*a, *b);
}
