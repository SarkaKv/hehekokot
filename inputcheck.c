/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inputcheck.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-02-06 09:39:41 by skvackov          #+#    #+#             */
/*   Updated: 2025-02-06 09:39:41 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*safemalloc(size_t size)
{
	void	*adress;

	adress = malloc(size);
	if (!adress)
		return (NULL);
	return (adress);
}

int	checkinput(char *argv, char **numberstofree)
{
	int	oki;

	oki = 1;
	if (argv == NULL)
		freeexit(numberstofree);
	if (argv[0] != '-' && argv[0] != '+' && (argv[0] > '9' || argv[0] < '0'))
	{
		ft_putstr_fd("Error\n", 1);
		freeexit(numberstofree);
	}
	while (argv[oki] != '\0')
	{
		if (argv[oki] < '0' || argv[oki] > '9')
		{
			ft_putstr_fd("Error\n", 1);
			freeexit(numberstofree);
		}
		oki++;
	}
	return (0);
}

char	**oneargumentcheck(char *argv1)
{
	int		counter;
	char	**numbers;

	counter = 0;
	numbers = ft_split(argv1, ' ');
	if (!numbers)
	{
		freeexit(0);
	}
	while (numbers[counter] != NULL)
	{
		checkinput(numbers[counter], numbers);
		counter++;
	}
	return (numbers);
}
