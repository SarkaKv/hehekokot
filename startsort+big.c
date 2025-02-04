/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-07 15:58:08 by skvackov          #+#    #+#             */
/*   Updated: 2025-01-07 15:58:08 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

// static void	callforindex(s_stack *a, int lenghtofstack)
// {
// 	s_stack	*temp;
// 	s_stack	*holdhead;
// 	int		index;
// 	int		curnumber;

// 	holdhead = a;
// 	index = 0;
// 	while (index < lenghtofstack)
// 	{
// 		temp = holdhead;
// 		curnumber = INT_MAX;
// 		while (temp)
// 		{
// 			if (temp->index == -1 && curnumber > temp->number)
// 				curnumber = temp->number;
// 			temp = temp->next;
// 		}
// 		a = holdhead;
// 		while (a != NULL)
// 		{
// 			if (curnumber == a->number && a->index == -1)
// 			{
// 				a->index = index;
// 				printf("\n %d   ", a->number);
// 				printf("%d \n", a->index);
// 				break ;
// 			}
// 			a = a->next;
// 		}
// 		index++;
// 	}
// }

static void callforindex(s_stack *a, int lenghtofstack)
{
    s_stack *temp;
    s_stack *holdhead;
    int index;
    int curnumber;
    s_stack *smallest_node;

    holdhead = a;
    index = 0;
    while (index < lenghtofstack)
    {
        temp = holdhead;
        curnumber = INT_MAX;
        smallest_node = NULL;
        
        // Find the smallest unindexed node
        while (temp)
        {
            if (temp->index == -1 && temp->number < curnumber)
            {
                curnumber = temp->number;
                smallest_node = temp;
            }
            temp = temp->next;
        }

        // Assign the correct index to the found node
        if (smallest_node)
        {
            smallest_node->index = index;
            printf("\n %d -> index: %d \n", smallest_node->number, smallest_node->index);
        }

        index++;
    }
}


static int	bitnumberindex(int lenghtyfella)
{
	int	bitcheck;

	bitcheck = 0;
	while ((lenghtyfella - 1) >> bitcheck)
	{
		bitcheck++;
	}
	return (bitcheck);
}


static int	actualradics(s_stack **a, s_stack **b, int bitnumberomax,
		int lenghtofstack)
{
	int		iteration;
	int j;
	iteration = 0;
	while (iteration < bitnumberomax)
	{
		j = 0;
		while(j < lenghtofstack)
		{

			if((((*a)->index >> iteration) & 1)  == 1)
				rota(a);
			else
				pushb(a, b);
			j++;
		}
		while(*b)
		{
			pusha(a, b);
		}
		iteration++;
	}
	return(1);
}

static void setindextom1(s_stack *a)
{
    while (a)
	{
		a->index = -1;
		a = a->next;
	}
}

void	startsort(s_stack **stacka)
{
	s_stack *stackb;
	int lenghtofstack;

	stackb = NULL;
	lenghtofstack = listlenght(*stacka);
	if (lenghtofstack <= 5)
	{
		printf("doing smallsort");
		smallsort(stacka, &stackb, lenghtofstack);
	}
	if (lenghtofstack > 5)
	{
		printf("not doing small sort");
        setindextom1(*stacka);
		callforindex(*stacka, lenghtofstack);
		int bitnumberomax = bitnumberindex(lenghtofstack);
		ft_putnbr_fd(bitnumberomax,1);

		actualradics(stacka, &stackb, bitnumberomax, lenghtofstack);
        freeexitstack(stacka, 1); 
	}
	return ;
}