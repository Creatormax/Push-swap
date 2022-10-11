/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 04:34:15 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/11 16:51:49 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	return_mid(t_list **a, int chunk)
{
	int	max;
	int min;
	int	mid;
	int	i;

	mid = 0;
	i = 0;
	max = -2147483648;
	min = 2147483647;
	if (chunk == 1)
		return (((t_stack *)(*a)->content)->num);
	while (i < chunk)
	{
		if (((t_stack *)(*a)->content)->num < min)
			min = ((t_stack *)(*a)->content)->num;
		else if (((t_stack *)(*a)->content)->num > max)
			max = ((t_stack *)(*a)->content)->num;
		*a = (*a)->next;
		i++;
	}
	if ((max + min) % 2 != 0)
		mid = ((max + min) / 2 + 1);
	else if ((max + min) % 2 == 0)
		mid = ((max + min) / 2);
	return (mid);
}

int	push_return(t_list **a, t_list **b, int mid)
{
	int	chunk;

	chunk = 0;
	while (*a && is_sorted(mid, *a) == 0)
	{	
		*a = ft_lstfirst(*a);
		if (((t_stack *)(*a)->content)->num >= mid)
		{
			*a = (*a)->next;
			rotate(*a);
			write(1, "ra\n", 3);
			chunk--;
		}
		else if (((t_stack *)(*a)->content)->num < mid)
		{
			push(a, *b);
			write(1, "pb\n", 3);
			if (chunk == 0)
			{
				*b = ft_lstlast(*b);
				*b = (*b)->prior;
				ft_lstdelone((*b)->next, free);
				(*b)->next = NULL;
			}
		}
		chunk++;
	}
	return (chunk);
}

void	push_return_2(t_list **a, t_list **b, int mid, int chunk)
{
	int	i;

	i = 0;
	while (*b && i < chunk)
	{	
		*b = ft_lstfirst(*b);
		if (((t_stack *)(*b)->content)->num <= mid)
		{
			*b = (*b)->next;
			rotate(*b);
			write(1, "rb\n", 3);
			i--;
		}
		else if (((t_stack *)(*a)->content)->num > mid)
		{
			push(b, *a);
			write(1, "pa\n", 3);
		}
		i++;
	}
}

int	find_mid(t_list **a)
{
	int	max;
	int min;
	int	mid;

	mid = 0;
	max = -2147483648;
	min = 2147483647;
	while ((*a)->next)
	{
		if (((t_stack *)(*a)->content)->num < min)
			min = ((t_stack *)(*a)->content)->num;
		else if (((t_stack *)(*a)->content)->num > max)
			max = ((t_stack *)(*a)->content)->num;
		*a = (*a)->next;
	}
	if ((max + min) % 2 != 0)
		mid = ((max + min) / 2 + 1);
	else if ((max + min) % 2 == 0)
		mid = ((max + min) / 2);
	return (mid);
}

void	process(t_list **a, t_list **b)
{
	int	*chunk;
	int	mid;
	int	og;
	int	i;

	i = 0;
	mid = find_mid(a);
	og = mid;
	chunk = malloc(sizeof(int) * (mid + 1));
	ft_bzero(chunk, mid + 1);
	while (stack_len(*a) < 2 && og > i)
	{
		*a = ft_lstfirst(*a);
		chunk[i] = push_return(a, b, mid);
		mid = find_mid(a);
		i++;
	}
	sort_2(a, b);
	og = 0;
	//while (og < i && chunk[og] != 1)
	//{
		*b = ft_lstfirst(*b);
		mid = return_mid(b, chunk[og]);
		push_return_2(b, a, mid, chunk[og]);
		og++;
		//printf("%d			%d\n", mid, chunk[og]);
	//}	
	//i = 0;
	//while (chunk[i] != -1094795586)
	//{
	//	printf("%d\n", chunk[i]);
	//	i++;
	//}
}
