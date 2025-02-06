/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instrcuts.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025-01-23 08:21:49 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-23 08:21:49 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap12(t_stack **stack)
{
	t_stack	*firstone;
	t_stack	*secondone;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		return ;
	}
	firstone = *stack;
	secondone = firstone->next;
	if (secondone->next)
	{
		firstone->next = secondone->next;
		secondone->next->prev = firstone;
	}
	else
	{
		firstone->next = NULL;
	}
	secondone->prev = NULL;
	secondone->next = firstone;
	firstone->prev = secondone;
	*stack = secondone;
	return ;
}

void	sa(t_stack **stack)
{
	ft_putstr_fd("sa\n", 1);
	swap12(stack);
}

void	sb(t_stack **stack)
{
	ft_putstr_fd("sb\n", 1);
	swap12(stack);
}

void	ss(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("ss\n", 1);
	swap12(stacka);
	swap12(stackb);
}
