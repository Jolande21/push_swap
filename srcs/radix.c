/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/19 11:58:49 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_maximum(t_stack *a)
{
	t_stack	*current;
	int		max;

	current = a;
	//printf("the first value to check in get_max: %d\n", current->value);
	max = current->value;
	
	//printf("the address of the next node: %p\n", current->next);
	while (current->next)
	{
		//printf("the next value to check: %d\n", current->next->value);
		if (current->next->value > max)
			max = current->next->value;
		current = current->next;
	}
	printf("the max int in the set: %d\n", max);
	return (max);
}
