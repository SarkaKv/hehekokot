/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smallsorts.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:12:53 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:12:53 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort3(t_stack *a, t_stack *b, int min, int pushkey)
{
	int	max;
	min = findmin(a);
	max = findmax(a);
	if (min == 1 && max == 0)
	{
		while(min-- >= 0)
			rra(&a);
	}
	else if (min == 0 && max == 1)
	{
		sa(&a);
		rota(&a);
	}
	else if (min == 1 && max == 2)
		sa(&a);
	else if (min == 2)
	{
		if (max == 0)
			sa(&a);
		rra(&a);
	}
	while (pushkey-- > 0)
		pusha(&a, &b);
	freeexitstack(&b, 0);
	freeexitstack(&a, 1);
}

void	sort4(t_stack *a, t_stack *b, int min, int pushkey)
{
	if (min == 1)
		sa(&a);
	else if (min == 2)
	{
		rra(&a);
		rra(&a);
	}
	else if (min == 3)
	{
		rra(&a);
	}
	pushb(&a, &b);
	sort3(a, b, min, pushkey);
}

void	sort5(t_stack *a, t_stack *b, int min, int pushkey)
{
	if (min == 1)
		sa(&a);
	else if (min == 2)
	{
		rota(&a);
		rota(&a);
	}
	else if (min == 3)
	{
		rra(&a);
		rra(&a);
	}
	else if (min == 4)
		rra(&a);
	pushb(&a, &b);
	sort4(a, b, min, pushkey);
}

void	smallsort(t_stack **stacka, t_stack **stackb, int sizestack)
{
	int	min;

	min = findmin(*stacka);
	if (sizestack == 2)
	{
		if (checkifsorted(*stacka) == 0)
			sa(stacka);
		return ;
	}
	else if (sizestack == 3)
		sort3(*stacka, *stackb, min, 0);
	else if (sizestack == 4)
		sort4(*stacka, *stackb, min, 1);
	else if (sizestack == 5)
		sort5(*stacka, *stackb, min, 2);
}
