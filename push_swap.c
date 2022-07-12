/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 11:18:33 by hmorales          #+#    #+#             */
/*   Updated: 2022/07/12 12:04:45 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	t_list	*copy;

	a = NULL;
	b = NULL;
	copy = NULL;
	if (argc < 2)
		ft_errormsg("Please submit a stack");
	initializer(argc, argv, &a, &copy);
}

void	checker(char **str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i][j] != NULL)
		{
			if (ft_isalpha(str[i][j]) == 1)
				ft_errormsg("There must be no letters in the stack");
			else if ((str[i][j] > '9' || str[i][j] < '0') \
			&& str[i][j] != '+' && str[i][j] != '-')
				ft_errormsg("There is a missuse in symbols");
			j++;
		}
		if (ft_atoi(str[i]) > 2147483647 || ft_atoi(str[i]) < -2147483648)
			ft_errormsg("Numbers on argument are out of bounds");
		i++;
	}
}	

void	savedata(int argc, char **argv, t_list **a, t_list **copy)
{
	char	**str;
	int		i;
	int		j;
	t_stack	*num;
	t_stack	*numcpy;

	i = 1;
	num = NULL;
	numcpy = NULL;
	while (i < argc)
	{
		str = ft_split((argv[i++]), ' ');
		j = 0;
		while (str[j])
		{
			num = malloc(sizeof(t_stack));
			num->num = ft_atoi(str[j]);
			ft_lstadd_back(a, ft_lstnew(num));
			numcpy = malloc(sizeof(t_stack));
			numcpy->num = ft_atoi(str[j++]);
			ft_lstadd_back(copy, ft_lstnew(numcpy));
		}
		ft_liberator(str);
	}
}

int	duplicates(t_list *a)
{
	while (a && a->next)
	{
		if (((t_stack *)a->content)->num == ((t_stack *)a->next->content)->num)
			return (1);
		a = a->next;
	}
	return (0);
}

void	initializer(int argc, char **argv, t_list **a, t_list **copy)
{
	int		i;
	char	**str;

	i = 1;
	while (argv[i])
	{
		str = ft_split(argv[i], ' ');
		checker(str);
		ft_liberator(str);
		i++;
	}
	savedata(argc, argv, a, copy);
	if (duplicates(a) == 1)
	{
		ft_lstclear(&(*a), free);
		ft_errormsg("There are duplicates in the stack");
	}
}
