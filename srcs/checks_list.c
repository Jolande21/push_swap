/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:55:56 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 12:58:13 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	//printf("the address of the first node: %p\n", current);
	while (current && current->next)
	{
		// check if the value (number) of the current element of the list
		// if it is greater than the value of the next number
		// then the list is not sorted
		//printf("the current element's value: %d\n", current->value);
		if (current->value > current->next->value)
			return (0);
		//printf("the address of the next node: %p\n", current->next);
		current = current->next;
	}
	return (1);
}

// check the size of the list
int	list_checks(t_stack **a)
{
	int	size;

	//printf("----------------------the size of the list:-------------------------\n");
	size = list_size(*a);
	if (size == 1)
		ft_error("the ")
	// {
	// 	write(1, "Error\n", 6);
	// 	exit(1);
	// }
	
	// check if the set of int values, is sorted
	if (!is_sorted(a))
	{
		//printf("the stack is not sorted.\n");
		// create an index of the int set in ascending order
		if (!index_stack(a))
		{
			printf("no indexation so the program stops here.\n");
			exit(1);
		}

		// sort the list based on the number of ints in the list = size
		if (size <= 5)
			sort_small_list(a, size);
		else
		{
			// convert created index to an int binary index
			binary_index(*a);
			// sort the created binary index
			sort_big_list(*a);
		}
	}
	else
	{
		printf("the stack is sorted!\n");
		exit(1);
	}
	return (0);
}



//printf("the number of elements in stack a: %d\n", size);