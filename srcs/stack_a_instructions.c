/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_a_instructions.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:35:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 16:48:50 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/* 
sa (swap a): swap the first 2 elements at the top of stack a
do nothing if there is only one or no elements 
*/

void	ft_sa(t_stack **a)
{
	t_stack	*second;

	if (!*a || !(*a)->next)
		return ;
	second = *a;
	*a = (*a)->next;
	second->next = (*a)->next;
	(*a)->next = second;  
}

// pa (push a): take the 1st element at the top of b and put it at the top of a
// do nothing if b is empty

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	if (!*b)
		return ;
	temp = *a;
	*a = *b;
	*b = (*b)->next;
	(*a)->next = temp;
}

// ra (rotate a): shift up all elements of stack a by 1
// the first element becomes the last one

void	ft_ra(t_stack **a)
{
	t_stack	*last_node;
	t_stack *temp;
	
	if (!*a)
		return ;
	temp = *a; 
	*a = (*a)->next; 
	last_node = ft_last_list(*a); 
	last_node->next = temp; 
	temp->next = NULL;
}

/*
rra (reverse rotate a): shift down all elements of stack a by 1
the last element becomes the first one
*/

void	ft_rra(t_stack **a)
{
	t_stack	*temp;
	int		i;

	i = 0;
	// store the address of the first node in a tmp pointer
	temp = *a; // 5850

	// loop through the stack until you find the last node
	// the head of the stack is now pointing to the last node
	// keep track of the number of nodes you need to loop through
	while ((*a)->next)
	{
		*a = (*a)->next; // 5820
		i++;
	}
	// assign the next pointer of the head to point to the 'old' first node (= stored in temp)
	(*a)->next = temp; 

	// go back to the before last node
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	// set the next pointer of the former last node to NULL
	temp->next = NULL;
}
