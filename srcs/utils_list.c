/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:56:54 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/13 13:03:35 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// returns the size of the list (the number of nodes created)

int	ft_list_size(t_stack *a)
{
	int	count;

	count = 0;
	while (a)
	{
		count++;
		a = a->next;
	}
	return (count);
}

// returns the last element of the list

t_stack	*ft_last_element_list(t_stack *head)
{
	t_stack	*last_element;

	last_element = head;
	while (last_element->next)
		last_element = last_element->next;
	return (last_element);
}

// adds a new element at the end of the list

void	ft_add_element_list_end(t_stack **a, t_stack *new_element)
{
	t_stack	*former_last;

	if (*a == NULL)
		*a = new_element;
	else
	{
		former_last = ft_last_element_list(*a);
		former_last->next = new_element;
	}
}

// creates a new element/node in the linked list

t_stack	*ft_create_list_element(int number)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = number;
	new_element->index = -1;
	new_element->next = NULL;
	return (new_element);
}
