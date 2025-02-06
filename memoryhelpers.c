/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memoryhelpers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:35:24 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:35:24 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	freeexit(char **numberstofree)
{
	int	i;

	i = 0;
	if (numberstofree)
	{
		while (numberstofree[i] != NULL)
		{
			free(numberstofree[i]);
			i++;
		}
		free(numberstofree);
	}
	exit(1);
}

void	freenoexitchar(char **numberstofree)
{
	int	i;

	i = 0;
	if (numberstofree)
	{
		while (numberstofree[i] != NULL)
		{
			free(numberstofree[i]);
			i++;
		}
		free(numberstofree);
	}
	return ;
}

void	freenoexitlongint(long int **numberstofree)
{
	int	i;

	i = 0;
	if (numberstofree)
	{
		while (numberstofree[i] != NULL)
		{
			free(numberstofree[i]);
			i++;
		}
		free(numberstofree);
	}
}

void	freeexitstack(t_stack **stack, int exitus)
{
	t_stack	*stack_cur;
	t_stack	*next;

	stack_cur = *stack;
	while (stack_cur != NULL)
	{
		next = stack_cur->next;
		free(stack_cur);
		stack_cur = next;
	}
	*stack = NULL;
	if (exitus == 1)
		exit(0);
	else
		return ;
}
