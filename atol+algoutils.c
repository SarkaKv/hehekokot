/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkandutils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 08:18:05 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-23 08:18:05 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// add check for more than one - -> shouldnt be accepted
long int myatol(char *str)
{
    long int sign = 1;
    long int results = 0;
    int counter = 0;
    if(str[counter] == '-')
    {
        sign = sign * -1;
        counter++;
    }
    while(str[counter] == '-' || str[counter] == '+')
    {
        counter++;
    }
    while(str[counter] != '\0')
    {
        results = results * 10;
        results = results + str[counter] - '0';
        counter++;
    }
    return(results * sign);
}

int checkifsorted(s_stack *stack)
{
    if(!stack || stack->next == NULL)
        freeexitstack(&stack, 1);
    s_stack *current = stack;
    while(current->next != NULL)
    {
        if(current->number < current->next->number)
            current = current->next;
        else
        { 
            return(0);
        }
    }
    return(1);
}

int	findmin(s_stack *stacka)
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

int findmax(s_stack *stacka)
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

int listlenght(s_stack *stacka)
{
    int listleghtnumber = 0;
    while(stacka)
    {
        listleghtnumber++;
        stacka = stacka->next;
    }
    return(listleghtnumber);
}
