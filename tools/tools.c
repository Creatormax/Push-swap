/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/05 15:33:51 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/17 10:55:37 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	print_stacks(t_list *a, t_list *b)
{
	int	n;
	int	size;

	n = 0;
	a = ft_lstfirst(a);
	b = ft_lstfirst(b);
	size = ft_lstsize(a);
	while (n < size)
	{
		printf("A :%d\n", ((t_stack *)(a)->content)->num);
		n++;
		a = a->next;
	}
	printf("\n");
	n = 0;
	size = ft_lstsize(b);
	while (n < size && size != 0)
	{
		printf("B :%d\n", ((t_stack *)(b)->content)->num);
		n++;
		b = b->next;
	}
	printf("\n");
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

int	find_max(t_list *a)
{
	int	i;
	int	max;

	i = ft_lstsize(a);
	max = ((t_stack *)(a)->content)->num;
	a = ft_lstfirst(a);
	while (i > 0)
	{
		if ((((t_stack *)(a)->content)->num) > max)
			max = ((t_stack *)(a)->content)->num;
		a = a->next;
		i--;
	}
	return (max);
}

int	find_min(t_list *a)
{
	int	i;
	int	min;

	i = ft_lstsize(a);
	min = ((t_stack *)(a)->content)->num;
	a = ft_lstfirst(a);
	while (i > 0)
	{
		if ((((t_stack *)(a)->content)->num) < min)
			min = ((t_stack *)(a)->content)->num;
		a = a->next;
		i--;
	}
	return (min);
}

//Poner num < -2147483648 en parse por que en linux es diferente a mac