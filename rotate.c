/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 11:16:32 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-23 11:16:32 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void rotting(s_stack **stack)
{
    if(!*stack || !(*stack)->next || !stack)
        return;
    s_stack *holdfirst = *stack;
    s_stack *holdlast = *stack;

    while(holdlast->next)
    {
        holdlast = holdlast->next;
    }
    *stack = holdfirst->next;
    (*stack)->prev = NULL;
    holdlast->next = holdfirst;
    holdfirst->prev = holdlast;
    holdfirst->next = NULL;
}


void rota(s_stack **stacka)
{
    ft_putstr_fd("ra\n", 1);
    rotting(stacka);

}
void rb(s_stack **stackb)
{
    ft_putstr_fd("rb\n", 1);
    rotting(stackb);
}
void rr(s_stack **stacka, s_stack **stackb)
{
    ft_putstr_fd("rr\n", 1);
    rotting(stacka);
    rotting(stackb);
} 


