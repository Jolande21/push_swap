/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_index.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:00 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/09 12:19:21 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// this function looks for the min int in the linked list a

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

// this function creates an index of the set of values provided as args

int	index_stack(t_stack **a)
{
	t_stack			*head;
	unsigned int	index;
	int				min_value1;
	int				min_value2;

	//printf("---------------stack a after creating ascending index:--------------\n");
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
	//print_stack(*a);
	return (1);
}

