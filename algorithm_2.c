/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:33:51 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 16:25:24 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sorted(t_list *a)
{
	int	i;

	i = 1;
	a = ft_lstfirst(a);
	while ((((t_stack *)(a)->content)->num < \
	((t_stack *)(a)->next->content)->num) && a)
	{
		if (((t_stack *)(a)->content)->num > \
		((t_stack *)(a)->next->content)->num)
		{
			i = 0;
			break ;
		}
		a = a->next;
	}
	return (i);
}

void	print_stack(t_list *a)
{
	a = ft_lstfirst(a);
	while ((t_stack *)(a)->content)
	{
		printf("%d\n", ((t_stack *)(a)->content)->num);
		if (a->next)
			a = a->next;
		else
			break ;
	}
	a = ft_lstfirst(a);
}
