/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   startsort+big.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 15:53:42 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-05 15:53:42 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static void	callforindex(t_stack *a, int lengthofstack)
{
	t_stack	*temp;
	t_stack	*smallest_node;
	int		index;
	int		curnumber;

	index = 0;
	while (index < lengthofstack)
	{
		temp = a;
		curnumber = INT_MAX;
		smallest_node = NULL;
		while (temp)
		{
			if (temp->index == -1 && temp->number < curnumber)
			{
				curnumber = temp->number;
				smallest_node = temp;
			}
			temp = temp->next;
		}
		if (smallest_node)
			smallest_node->index = index;
		index++;
	}
}

static int	bitnumberindex(int lenghtyfella)
{
	int	bitcheck;

	bitcheck = 0;
	while ((lenghtyfella - 1) >> bitcheck)
	{
		bitcheck++;
	}
	return (bitcheck);
}

static int	actualradics(t_stack **a, t_stack **b, int bitnumberomax,
		int lenghtofstack)
{
	int	iteration;
	int	j;
	int	original_size;

	iteration = 0;
	while (iteration < bitnumberomax)
	{
		j = 0;
		original_size = lenghtofstack;
		while (j < original_size)
		{
			if ((((*a)->index >> iteration) & 1) == 1)
				rota(a);
			else
				pushb(a, b);
			j++;
		}
		while (*b)
			pusha(a, b);
		if (checkifsorted(*a) == 1 && b == NULL)
			return (1);
		iteration++;
	}
	return (1);
}

static void	setindextom1(t_stack *a)
{
	while (a)
	{
		a->index = -1;
		a = a->next;
	}
}

void	startsort(t_stack **stacka)
{
	t_stack	*stackb;
	int		lenghtofstack;
	int		bitnumberomax;

	stackb = NULL;
	lenghtofstack = listlenght(*stacka);
	if (lenghtofstack <= 5)
	{
		smallsort(stacka, &stackb, lenghtofstack);
	}
	if (lenghtofstack > 5)
	{
		setindextom1(*stacka);
		callforindex(*stacka, lenghtofstack);
		bitnumberomax = bitnumberindex(lenghtofstack);
		actualradics(stacka, &stackb, bitnumberomax, lenghtofstack);
	}
	freeexitstack(&stackb, 0);
	freeexitstack(stacka, 1);
	return ;
}
