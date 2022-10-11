/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/11 15:09:37 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/11 16:20:57 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_2(t_list **a, t_list **b)
{
	*a = ft_lstfirst(*a);
	*b = ft_lstfirst(*b);
	if (((t_stack *)(*a)->content)->num > \
	((t_stack *)(*a)->next->content)->num)
	{
		*a = (*a)->next;
		rotate(*a);
		*a = ft_lstfirst(*a);
		write(1, "ra\n", 3);
		push(a, *b);
		write(1, "pb\n", 3);
	}
	else
	{
		push(a, *b);
		write(1, "pb\n", 3);
	}
}