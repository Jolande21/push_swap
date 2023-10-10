/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:55:56 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 15:52:46 by jsteenpu         ###   ########.fr       */
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

int	list_checks(t_stack **a)
{
	int	size;

	//printf("----------------------the size of the list:-------------------------\n");
	size = list_size(*a);
	if (size == 1)
		ft_error("there is only one int given as argument.");
	if (is_sorted(a))
		ft_error("the stack is already sorted.");
	return (1);
}



//printf("the number of elements in stack a: %d\n", size);