/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 15:55:30 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-05 15:55:30 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverserot(t_stack **stack)
{
	t_stack	*holdinglast;
	t_stack	*newend;

	holdinglast = *stack;
	newend = NULL;
	if (!stack || !*stack || !(*stack)->next)
		return ;
	while (holdinglast->next)
	{
		newend = holdinglast;
		holdinglast = holdinglast->next;
	}
	newend->next = NULL;
	holdinglast->prev = NULL;
	holdinglast->next = *stack;
	(*stack)->prev = holdinglast;
	*stack = holdinglast;
}

void	rra(t_stack **stacka)
{
	ft_putstr_fd("rra\n", 1);
	reverserot(stacka);
}

void	rrb(t_stack **stackb)
{
	ft_putstr_fd("rrb\n", 1);
	reverserot(stackb);
}

void	doublereverserot(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("rrr\n", 1);
	reverserot(stacka);
	reverserot(stackb);
}
