/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:17:43 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:17:43 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct t_stack
{
	int				number;
	int				index;
	struct t_stack	*next;
	struct t_stack	*prev;
}	t_stack;

int		checkinput(char *argv, char **numberstofree);
char	**oneargumentcheck(char *argv1);
void	checkfordoubles(long int **original, int lenght);
void	freeexit(char **numberstofree);
void	*safemalloc(size_t size);
void	freenoexitchar(char **numberstofree);
void	freenoexitint(int **numberstofree);
void	freeexitstack(t_stack **stack, int exit);
void	freenoexitlongint(long int **numberstofree);
void	makenumbers(char **mynumbers);
long	int	myatol(char *str);
void	makestack(long int **numbers);
void	pushintostack(t_stack **stack, int currentint,
			long int **incaseofmallocfail);
int		checkifsorted(t_stack *stack);
int		findmax(t_stack *stacka);
int		findmin(t_stack *stacka);
int		listlenght(t_stack *stacka);
void	startsort(t_stack **stack);
void	smallsort(t_stack **stacka, t_stack **stackb, int sizestack);
void	sort3(t_stack *a, t_stack *b, int min, int pushkey);
void	sort4(t_stack *a, t_stack *b, int min, int pushkey);
void	sort5(t_stack *a, t_stack *b, int min, int pushkey);
void	ss(t_stack **stacka, t_stack **t_stackb);
void	sb(t_stack **stack);
void	sa(t_stack **stack);
void	swap12(t_stack **stack);
void	push(t_stack **pusher, t_stack **reciever);
void	pushb(t_stack **stacka, t_stack **stackb);
void	pusha(t_stack **stacka, t_stack **stackb);
void	doublereverserot(t_stack **stacka, t_stack **t_stackb);
void	rrb(t_stack **stackb);
void	rra(t_stack **stacka);
void	reverserot(t_stack **t_stack);
void	rb(t_stack **stackb);
void	rr(t_stack **stacka, t_stack **stackb);
void	rota(t_stack **stacka);
void	rotting(t_stack **stack);

#endif