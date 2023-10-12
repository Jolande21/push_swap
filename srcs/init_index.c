/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:00 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 17:32:20 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// looks for the min int in the linked list a
// if index has value -1; set the new minimum value at that index

static int	get_minimum(t_stack **a)
{
	t_stack	*head;
	int		min_value;

	head = *a;
	min_value = INT_MAX;
	while (head)
	{
		if (head->value < min_value && head->index == -1)
			min_value = head->value;
		head = head->next;
	}
	return (min_value);
}

// creates an index of the integer values (provided in args) 
// stored in linked list a

int	init_index_stack(t_stack **a)
{
	t_stack			*current;
	unsigned int	index;
	int				min_value1;
	int				min_value2;

	current = *a;
	index = -1;
	min_value1 = get_minimum(a); 
	min_value2  = min_value1; 
	while (current)
	{
		if (current->value == min_value1 && current->index == -1)
		{
			index++;
			current->index = index;
			min_value2 = get_minimum(a);
		}
		if (min_value1 != min_value2)
		{
			current = *a;
			min_value1 = min_value2;
		}
		else
			current = current->next;
	}
	return (1);
}

