/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-23 10:37:32 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-23 10:37:32 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void push(s_stack **pusher, s_stack **reciever)
{
    if(!*pusher)
        return;
    s_stack *hold = *pusher;
    *pusher = (*pusher)->next;
    if(*pusher)
        (*pusher)->prev = NULL;
    if(!*reciever)
    {
        *reciever = hold;
        return;
    }
    hold->next = *reciever;
    (*reciever)->prev = hold;
    *reciever = hold;
}

void pushb(s_stack **stacka, s_stack **stackb)
{
    ft_putstr_fd("pb\n", 1);
    push(stacka, stackb);
}

void pusha(s_stack **stacka, s_stack **stackb)
{
    ft_putstr_fd("pa\n", 1);
    push(stackb, stacka);
}
