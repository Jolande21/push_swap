/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:55:56 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 18:26:18 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// checks if the linked list a is sorted
// returns 0 if the list is not sorted
// returns 1 if the list is sorted 

int	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (0);
		current = current->next;
	}
	return (1);
}

// checks the size of the list and if the list is sorted
// if the list is not sorted,
// creates index of the set of ints stored in the linked list
// sorting based on size of the list (small <= 5 / big < 5)

void	init_sorting(t_stack **a, t_stack **b)
{
	int	size;

	size = list_size(*a);
	if (size == 1)
		exit(1);
	if (is_sorted(a))
		exit(1);
	if (!init_index_stack(a))
		exit(1);
	if (size <= 5)
		sort_small_list(a, b, size);
	else
		sort_big_list(a, b);
}
