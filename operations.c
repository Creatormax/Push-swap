/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:55 by hmorales          #+#    #+#             */
/*   Updated: 2022/08/10 13:46:09 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a)
{
	int	copy;

	copy = ((t_stack *)a->content)->num;
	((t_stack *)a->content)->num = ((t_stack *)a->next->content)->num;
	((t_stack *)a->next->content)->num = copy;
}

void	push(t_list *a, t_list *b)
{
	ft_lstadd_front(b, ((t_stack *)a->content)->num);
}

void	rotate(t_list *a)
{
	ft_lstadd_back(a, ((t_stack *)a->content)->num);
	while (a)
	{
		((t_stack *)a->content)->num = ((t_stack *)a->next->content)->num;
		a->next;
	}
}
//sospecho que hay que borrar el primer elemento despues de llevarlo abajo

void	rev_rotate(t_list *a)
{
	while (a)
	{
		((t_stack *)a->next->content)->num = ((t_stack *)a->content)->num;
		a->next;
	}
	ft_lstadd_front(a, ((t_stack *)a->content)->num);
}
