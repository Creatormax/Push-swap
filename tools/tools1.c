/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmorales <hmorales@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 11:36:14 by hmorales          #+#    #+#             */
/*   Updated: 2023/02/03 10:50:24 by hmorales         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_list	*b_not_included(t_list *b)
{
	if (!b)
		b = malloc(sizeof(t_stack *));
	return (b);
}