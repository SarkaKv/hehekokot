/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-12-27 16:46:26 by skvackov          #+#    #+#             */
/*   Updated: 2024-12-27 16:46:26 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdlib.h>
# include <unistd.h>
#include <stdio.h>

typedef struct t_stack
{
	int				number;
	int				index;
	struct t_stack	*next;
	struct t_stack	*prev;
}					s_stack;

// argumentcheking
int					checkinput(char *argv, char **numberstofree);
char				**oneargumentcheck(char *argv1);
void				checkfordoubles(long int **original, int lenght);

// memory helpers
void				freeexit(char **numberstofree);
void				*safemalloc(size_t size);
void				freenoexitchar(char **numberstofree);
void				freenoexitint(int **numberstofree);
void				freeexitstack(s_stack **stack, int exit);
void	freenoexitlongint(long int **numberstofree);
// making stack but make it stupidly complicated
void				makenumbers(char **mynumbers);
long int			myatol(char *str);
void				makestack(long int **numbers);
void				pushintostack(s_stack **stack, int currentint,
						long int **incaseofmallocfail);

// cheking for sort,lenght, index max and min
int					checkifsorted(s_stack *stack);
int					findmax(s_stack *stacka);
int					findmin(s_stack *stacka);
int					listlenght(s_stack *stacka);
// sorting
void				startsort(s_stack **stack);
// sorting 1-5 (rest are void functions)
void				smallsort(s_stack **stacka, s_stack **stackb,
						int sizestack);
void	sort3(s_stack *a, s_stack *b);
void sort4(s_stack *a, s_stack *b);
void sort5(s_stack  *a, s_stack *b);
// instructs
void				ss(s_stack **stacka, s_stack **s_stackb);
void				sb(s_stack **stack);
void				sa(s_stack **stack);
void				swap12(s_stack **stack);
void				push(s_stack **pusher, s_stack **reciever);
void				pushb(s_stack **stacka, s_stack **stackb);
void				pusha(s_stack **stacka, s_stack **stackb);
void				doublereverserot(s_stack **stacka, s_stack **s_stackb);
void				rrb(s_stack **stackb);
void				rra(s_stack **stacka);
void				reverserot(s_stack **s_stack);
void				rb(s_stack **stackb);
void				rr(s_stack **stacka, s_stack **stackb);
void				rota(s_stack **stacka);
void				rotting(s_stack **stack);

#endif