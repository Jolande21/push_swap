/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/18 17:52:42 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_maximum(t_stack *a)
{
	t_stack	*current;
	int		max;

	current = a;
	printf("the first value to check in get_max: %d\n", current->value);
	max = current->value;
	
	printf("the address of the next node: %p\n", current->next);
	while (current->next)
	{
		printf("the next value to check: %d\n", current->next->value);
		if (current->next->value > max)
			max = current->next->value;
		current = current->next;
	}
	printf("the max int in the set: %d\n", max);
	return (max);
}

// this function sets the index of each element in the linked list 
// in binairy format

void	binaire_index(t_stack *a)
{
	t_stack	*current;
	int		base;
	int		i;
	char	*binairy;

	current = a;
	base = 2;
	// divide the index by 2
	// stel = 8
	// * 8 / 2 = 4 rem = 0 - 1
	// 4 / 2 = 2 rem = 0 - 2
	// 2 / 2 = 1 rem = 0 - 3
	// 1 / 2 = 0 rem = 1
	i = 0; 
	while ((current->index) / base > 0)
		i++;
	
}

