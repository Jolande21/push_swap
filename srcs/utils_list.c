/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:56:54 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/12 10:41:52 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// returns the size of the list (the number of nodes created)

int	list_size(t_stack *a)
{
	int	count;

	count = 0;
	//printf("list_size: the address of 1st node: %p\n", a);
	while (a)
	{
		count++;
		a = a->next;
		//printf("list_size: the address of the next node: %p\n", a);
	}
	return (count);
}

// returns the last element of the list

t_stack	*ft_last_element_list(t_stack *head)
{
	t_stack *last_element;

	last_element = head;
	while (last_element->next)
		last_element = last_element->next;
	return (last_element);
}

// add a new element at the end of the list

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

// creates a new element in a list

t_stack	*ft_create_list_element(int number)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = number;
	new_element->index = -1;
	new_element->index_bin = 0;
	new_element->next = NULL;
	return (new_element);
}

// print values stored in the created stack/linked list

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		printf("value: %d\t index: %d\t address next: %p\n", current->value, current->index, current->next);
		current = current->next;
	}
	printf("\n");
}