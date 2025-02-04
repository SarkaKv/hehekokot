/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverserot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 14:26:09 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-23 14:26:09 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void reverserot(s_stack **stack)
{
    if(!stack || !*stack || !(*stack)->next)
        return;
    s_stack *holdinglast = *stack;
    s_stack *newend = NULL;
    while(holdinglast->next)
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


void rra(s_stack **stacka)
{
    ft_putstr_fd("rra\n", 1);
    reverserot(stacka);
}

void rrb(s_stack **stackb)
{
    ft_putstr_fd("rrb\n", 1);
    reverserot(stackb);
}

void doublereverserot(s_stack **stacka, s_stack **stackb)
{
    ft_putstr_fd("rrr\n", 1);
    reverserot(stacka);
    reverserot(stackb);
}