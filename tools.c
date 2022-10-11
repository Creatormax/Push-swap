/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:33:51 by hmorales          #+#    #+#             */
/*   Updated: 2022/10/11 16:15:04 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	is_sorted(int mid, t_list *a)
{
	int	chk;

	chk = 1;
	a = ft_lstfirst(a);
	while (a->next)
	{
		if (((t_stack *)(a)->content)->num < mid)
		{
			chk = 0;
			return (chk);
		}
		a = a->next;
	}
	//printf("%d", chk);
	return (chk);
}

void	parse(char *str)
{
	int	num;

	num = 0;
	num = ft_atoi(str);
	if (num > 2147483647 || num < -2147483648)
		ft_errormsg("Int overflow detected");
}

int	stack_len(t_list *a)
{
	int	i;

	i = 0;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}
