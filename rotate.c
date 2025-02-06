/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-05 15:53:05 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-05 15:53:05 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotting(t_stack **stack)
{
	t_stack	*holdfirst;
	t_stack	*holdlast;

	holdfirst = *stack;
	holdlast = *stack;
	if (!*stack || !(*stack)->next || !stack)
		return ;
	while (holdlast->next)
	{
		holdlast = holdlast->next;
	}
	*stack = holdfirst->next;
	(*stack)->prev = NULL;
	holdlast->next = holdfirst;
	holdfirst->prev = holdlast;
	holdfirst->next = NULL;
}

void	rota(t_stack **stacka)
{
	ft_putstr_fd("ra\n", 1);
	rotting(stacka);
}

void	rb(t_stack **stackb)
{
	ft_putstr_fd("rb\n", 1);
	rotting(stackb);
}

void	rr(t_stack **stacka, t_stack **stackb)
{
	ft_putstr_fd("rr\n", 1);
	rotting(stacka);
	rotting(stackb);
}
