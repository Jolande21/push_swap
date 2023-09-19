/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 18:56:54 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 19:28:50 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// returns the last element of the list

t_stack	*ft_last_list(t_stack *head)
{
	t_stack *temp;

	temp = head;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// add a new element at the end of the list

void	ft_add_element_end(t_stack **a, t_stack *new_element)
{
	t_stack	*former_last;
	
	if (!new_element)
		return ;
	if (*a == NULL)
		*a = new_element;
	else
	{
		former_last = ft_last_list(*a);
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
