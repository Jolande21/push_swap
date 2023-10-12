/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:00 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 13:42:16 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// looks for the min int in the linked list a

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
	t_stack			*head;
	unsigned int	index;
	int				min_value1;
	int				min_value2;

	head = *a;
	index = -1;
	min_value1 = get_minimum(a); 
	min_value2  = min_value1; 
	while (head)
	{
		if (head->value == min_value1 && head->index == -1)
		{
			index++;
			head->index = index;
			min_value2 = get_minimum(a);
		}
		if (min_value1 != min_value2)
		{
			head = *a;
			min_value1 = min_value2;
		}
		else
			head = head->next;
	}
	return (1);
}

