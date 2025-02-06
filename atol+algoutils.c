/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atol+algoutils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:42:34 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:42:34 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int	myatol(char *str)
{
	long int	sign;
	long int	results;
	int			counter;

	sign = 1;
	results = 0;
	counter = 0;
	if (str[counter] == '-')
	{
		sign = sign * -1;
		counter++;
	}
	while (str[counter] == '-' || str[counter] == '+')
	{
		counter++;
	}
	while (str[counter] != '\0')
	{
		results = results * 10;
		results = results + str[counter] - '0';
		counter++;
	}
	return (results * sign);
}

int	checkifsorted(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	if (!stack || stack->next == NULL)
		freeexitstack(&stack, 1);
	while (current->next != NULL)
	{
		if (current->number < current->next->number)
			current = current->next;
		else
		{
			return (0);
		}
	}
	return (1);
}

int	findmin(t_stack *stacka)
{
	int	isnumber;
	int	whereinstack;
	int	correctindex;

	if (!stacka)
		return (-1);
	isnumber = stacka->number;
	whereinstack = 0;
	correctindex = 0;
	while (stacka)
	{
		if (stacka->number < isnumber)
		{
			isnumber = stacka->number;
			correctindex = whereinstack;
		}
		stacka = stacka->next;
		whereinstack++;
	}
	return (correctindex);
}

int	findmax(t_stack *stacka)
{
	int	isnumber;
	int	whereinstack;
	int	correctindex;

	if (!stacka)
		return (-1);
	isnumber = stacka->number;
	whereinstack = 0;
	correctindex = 0;
	while (stacka)
	{
		if (stacka->number > isnumber)
		{
			isnumber = stacka->number;
			correctindex = whereinstack;
		}
		stacka = stacka->next;
		whereinstack++;
	}
	return (correctindex);
}

int	listlenght(t_stack *stacka)
{
	int	listleghtnumber;

	listleghtnumber = 0;
	while (stacka)
	{
		listleghtnumber++;
		stacka = stacka->next;
	}
	return (listleghtnumber);
}
