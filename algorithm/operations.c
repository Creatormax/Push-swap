/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:13:55 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/18 17:33:32 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list **a, char *op)
{
	int	copy;

	*a = b_not_included(*a);
	if (ft_lstsize(*a) < 2)
		return ;
	copy = ((t_stack *)(*a)->content)->num;
	((t_stack *)(*a)->content)->num = ((t_stack *)(*a)->next->content)->num;
	((t_stack *)(*a)->next->content)->num = copy;
	*a = ft_lstfirst(*a);
	write(1, op, ft_strlen(op));
}

void	push(t_list **src, t_list **dest, char *op)
{
	t_list	*copy;

	copy = ft_lstfirst(*src);
	if (*src != NULL)
	{
		ft_lstadd_front(dest, ft_lstnew(copy->content));
		*src = copy->next;
		if (ft_lstsize(*src) != 0)
		{
			free((*src)->prior);
			(*src)->prior = NULL;
		}
		else
			free(copy);
	}
	*src = ft_lstfirst(*src);
	*dest = ft_lstfirst(*dest);
	write(1, op, ft_strlen(op));
}

void	rotate(t_list **a, char *op)
{
	t_list	*copy;

	*a = b_not_included(*a);
	if (ft_lstsize(*a) < 2)
		return ;
	copy = ft_lstlast(*a);
	copy->next = *a;
	(*a)->prior = copy;
	(*a)->next->prior = NULL;
	free((*a)->next->prior);
	(*a)->next = NULL;
	free((*a)->next);
	*a = ft_lstfirst(*a);
	write(1, op, ft_strlen(op));
}

void	rev_rotate(t_list **a, char *op)
{
	t_list	*copy;

	*a = b_not_included(*a);
	if (ft_lstsize(*a) < 2)
		return ;
	copy = ft_lstlast(*a);
	copy->next = *a;
	(*a)->prior = copy;
	copy->prior->next = NULL;
	free(copy->prior->next);
	copy->prior = NULL;
	free(copy->prior);
	*a = ft_lstfirst(*a);
	write(1, op, ft_strlen(op));
}
