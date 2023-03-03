/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:36:14 by hmorales          #+#    #+#             */
/*   Updated: 2023/03/03 10:49:11 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*b_not_included(t_list *b)
{
	if (!b)
		b = malloc(sizeof(t_stack *));
	return (b);
}

int	position_list_fw(t_list *a, int ni, int nf)
{
	int	i;
	int	num;
	int	size;

	i = 0;
	size = ft_lstsize(a);
	while (a->next && (i < size))
	{
		num = ((t_stack *)(a)->content)->num;
		if ((num >= ni) && (num <= nf))
			break ;
		a = a->next;
		i++;
	}
	if (i > (size / 2))
		i = i - size;
	return (i);
}

int	position_list_bw(t_list *a, int ni, int nf)
{
	int	i;
	int	num;
	int	size;

	i = 1;
	size = ft_lstsize(a);
	a = ft_lstlast(a);
	while (a->prior && (i < size))
	{
		num = ((t_stack *)(a)->content)->num;
		if ((num >= ni) && (num <= nf))
			break ;
		a = a->prior;
		i++;
	}
	if (i > (size / 2))
		i = size - i;
	else
		i = i * (-1);
	return (i);
}

void	terminator(t_list **a)
{
	int	i;
	int	size;

	size = ft_lstsize(*a);
	i = 0;
	while (size > i)
	{
		free((t_stack *)(*a)->content);
		free((t_stack *)(*a));
		i++;
		(*a) = (*a)->next;
	}
	free(*a);
}
