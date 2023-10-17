/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:00 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/17 13:08:04 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// looks for the min int in the linked list (stack a)
// if index has value -1 > set the new minimum value at that index

static int	get_minimum(t_stack **a)
{
	t_stack	*current;
	int		min_value;

	current = *a;
	min_value = 2147483647;
	while (current)
	{
		if (current->value < min_value && current->index == -1)
			min_value = current->value;
		current = current->next;
	}
	return (min_value);
}

// creates an index of the integer values (provided in args) 
// stored in the linked list (stack a)

int	init_index_stack(t_stack **a)
{
	t_stack			*current;
	unsigned int	index;
	int				min_value;

	current = *a;
	index = -1;
	min_value = get_minimum(a);
	while (current)
	{
		if (current->value == min_value && current->index == -1)
		{
			current->index = index++;
			current = *a;
			min_value = get_minimum(a);
		}
		else
			current = current->next;
	}
	return (1);
}
