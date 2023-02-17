/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 10:46:58 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/17 12:04:15 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_check(t_list **a, t_list **b)
{
	int	nf;
	int	i;
	int	size;

	i = 0;
	size = ft_lstsize(*b);
	while (size > i)
	{
		*b = ft_lstlast(*b);
		nf = ((t_stack *)(*b)->content)->num;
		*b = ft_lstfirst(*b);
		if (((t_stack *)(*b)->content)->num < nf)
		{
			while (((t_stack *)(*b)->content)->num < nf)
				rev_rotate(b, "rrb\n");
		}
		push(b, a, "pa\n");
		i++;
	}
}
