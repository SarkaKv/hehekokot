/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:14:24 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:14:24 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **pusher, t_stack **receiver)
{
	t_stack	*hold;

	hold = *pusher;
	if (!*pusher)
		return ;
	*pusher = (*pusher)->next;
	if (*pusher)
		(*pusher)->prev = NULL;
	hold->next = *receiver;
	if (*receiver)
		(*receiver)->prev = hold;
	*receiver = hold;
	hold->prev = NULL;
}

void	pushb(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("pb\n", 1);
	push(stacka, stackb);
}

void	pusha(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("pa\n", 1);
	push(stackb, stacka);
}
