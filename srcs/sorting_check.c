/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:55:56 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/20 11:41:33 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ft_is_sorted(t_stack *a)
{
	t_stack	*current;

	current = a;
	printf("the address of the first node: %p\n", current);
	while (current)
	{
		// check if the value (number) of the current element of the list
		// if it is greater than the value of the next number
		// then the list is not sorted
		//printf("the current element's value: %d\n", current_element->value);
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}
