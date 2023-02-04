/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:36:14 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/04 13:35:37 by hmorales         ###   ########.fr       */
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

	i = 0;
	while ((((t_stack *)(a)->content)->num < ni) || (((t_stack *)(a)->content)->num > nf))
	{
		a = a->next;
		i++;
	}
	if (i > (ft_lstsize(a) / 2))
		i = i - (ft_lstsize(a) + 1);
	return (i);
}

int	position_list_bw(t_list *a, int ni, int nf)
{
	int	i;

	i = ft_lstsize(a);
	a = ft_lstlast(a);
	while ((((t_stack *)(a)->content)->num < ni) || (((t_stack *)(a)->content)->num > nf))
	{
		a = a->prior;
		i--;
	}
	if (i > (ft_lstsize(a) / 2))
		i = i - (ft_lstsize(a) + 1);
	return (i);
}
