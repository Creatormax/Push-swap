/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:55 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/05 16:40:50 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_list *a)
{
	int	copy;

	if (!a || !(t_stack *)a->content || !(t_stack *)a->next->content)
		ft_errormsg("List not pushed");
	a = ft_lstfirst(a);
	copy = ((t_stack *)a->content)->num;
	((t_stack *)a->content)->num = ((t_stack *)a->next->content)->num;
	((t_stack *)a->next->content)->num = copy;
}

void	push(t_list **pushed, t_list *put)
{
	if (!pushed || !put)
		ft_errormsg("Not enough data");
	*pushed = ft_lstfirst(*pushed);
	put = ft_lstfirst(put);
	((t_stack *)put->content)->num = ((t_stack *)(*pushed)->content)->num;
	*pushed = (*pushed)->next;
	ft_lstdelone((*pushed)->prior, free);
	(*pushed)->prior = NULL;
}

void	rotate(t_list *a)
{
	t_list	*copy;

	copy = ft_lstnew(malloc(sizeof(t_stack)));
	if (!a || !copy)
		ft_errormsg("Not enough data");
	a = ft_lstfirst(a);
	((t_stack *)copy->content)->num = ((t_stack *)a->content)->num;
	ft_lstadd_back(&a, ft_lstnew(copy->content));
	a = ft_lstfirst(a);
	a = a->next;
	ft_lstdelone(a->prior, free);
	a->prior = NULL;
}

void	rev_rotate(t_list *a)
{
	t_list	*copy;

	copy = ft_lstnew(malloc(sizeof(t_stack)));
	if (!a || !copy)
		ft_errormsg("Not enough data");
	a = ft_lstfirst(a);
	ft_lstadd_front(&a, ft_lstnew(copy->content));
	a = ft_lstlast(a);
	((t_stack *)copy->content)->num = ((t_stack *)a->content)->num;
	a = ft_lstlast(a);
	a = a->prior;
	ft_lstdelone(a->next, free);
	a->next = NULL;
}
