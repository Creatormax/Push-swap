/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 04:34:15 by hmorales          #+#    #+#             */
/*   Updated: 2022/09/17 17:27:13 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_mid(t_list **a, int chunk)
{
	int max_min[2];
	int mid;
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (((t_stack *)(*a)->content)->num < max_min[1])
			max_min[1] = ((t_stack *)(*a)->content)->num; 
		else if (((t_stack *)(*a)->content)->num > max_min[0])
			max_min[0] = ((t_stack *)(*a)->content)->num;
		*a = (*a)->next;
		i++;
	}
	if ((max_min[0] + max_min[1]) % 2 != 0)
		mid = (max_min[0] + max_min[1]) / 2 + 1;
	else 
		mid = (max_min[0] + max_min[1]) / 2;
	return (mid);	
}

int	push_return(t_list **a, t_list **b, int mid)
{
	int	chunk;

	chunk = 0;
	while (*a)
	{
		if (((t_stack *)(*a)->content)->num > mid)
		{
			rotate(*a);
			write(1, "ra\n", 3);
			chunk--;
		}
		else
		{
			push(*a, *b);
			write(1, "pb\n", 3);
			*a = (*a)->next;
		}
		chunk++;
	}
	return (chunk);
}

void	push_return_2(t_list **a, t_list **b, int mid, int chunk)
{
	int	i;

	i = 0;
	while (i < chunk)
	{
		if (((t_stack *)(*a)->content)->num > mid)
		{
			rotate(*a);
			write(1, "rb\n", 3);
			i--;
		}
		else
		{
			push(*a, *b);
			write(1, "pa\n", 3);
			*a = (*a)->next;
		}
		i++;
	}
}

int	find_mid(t_list **a)
{
	int max_min[2];
	int mid;

	ft_loadmatrix(((t_stack *)(*a)->content)->num, max_min);
	while ((*a)->next)
	{
		if (((t_stack *)(*a)->content)->num < max_min[1])
			max_min[1] = ((t_stack *)(*a)->content)->num; 
		else if (((t_stack *)(*a)->content)->num > max_min[0])
			max_min[0] = ((t_stack *)(*a)->content)->num;
		*a = (*a)->next;
	}
	if ((max_min[0] + max_min[1]) % 2 != 0)
		mid = (max_min[0] + max_min[1]) / 2 + 1;
	else 
		mid = (max_min[0] + max_min[1]) / 2;
	return (mid);
}

void	process(t_list **a, t_list **b)
{
	int	*chunk;
	int	mid;

	chunk = NULL;
	while ((*a)->next)
	{
		mid = find_mid(a);
		*chunk = push_return(a, b, mid);
		chunk++;
	}
	while (*b && *chunk)
	{
		mid = return_mid(b, *chunk);
		push_return_2(b, a, mid, *chunk);
		chunk--;
	}
}
