/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: skvackov <skvackov@student.42.fr>          #+#  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2024-12-27 16:46:23 by skvackov          #+#    #+#             */
/*   Updated: 2024-12-27 16:46:23 by skvackov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


static char	*ft_strcpy(char *dest, const char *src)
{
	char *original_dest = dest;

	while (*src)
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';

	return (original_dest);
}

int	main(int argc, char **argv)
{
	int counter;
	char **numbers;

	counter = 1;
	if (argc == 2)
	{
		numbers = oneargumentcheck(argv[1]);
		makenumbers(numbers);
	}
	if (argc > 2)
	{
		numbers = safemalloc(sizeof(char *) * argc);
		while (counter < argc)
		{
			numbers[counter - 1] = safemalloc(sizeof(char)
					* (ft_strlen(argv[counter]) + 1));
			ft_strcpy(numbers[counter - 1], argv[counter]);
			checkinput(numbers[counter - 1], numbers);
			counter++;
		}
		numbers[argc - 1] = NULL;
		makenumbers(numbers);
		freeexit(numbers);
	}
	return (0);
}
