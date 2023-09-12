/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:43 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/12 16:27:59 by jsteenpu         ###   ########.fr       */
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

	// save a pointer to the first node in second
	second = *a;

	// update a so that it is now the address of the second node
	*a = (*a)->next;
	
	// update tmp->next to point to the 3rd node. 
	second->next = (*a)->next;
	
	// update *a->next to point to second node
	(*a)->next = second;  
}


/*
sb (swap b): swap the first 2 elements at the top of stack b
do nothing if there is only one or no elements
*/

void	ft_sb(t_stack **b)
{
	t_stack	*second;

	// save b pointer to the first node in second
	second = *b;

	// update b so that it is now the address of the second node
	*b = (*b)->next;
	
	// update second->next to point the first next
	second->next = (*b)->next;
	
	// update *a->next to point to second node
	(*b)->next = second;  
}
/*
ss: sa and sb at the same time
*/

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}


// pa (push a): take the 1st element at the top of b and put it at the top of a
// do nothing if b is empty



// pb (push b): take the 1st element at the top of a and put it at the top of b
// do nothing if a is empty

// ra (rotate a): shift up all elements of stack a by 1
// the first element becomes the last one

// rb (rotate b): shift up all elements of stack b by 1
// the first element becomes the last one


// rr: ra and rb at the same time

// rra (reverse rotate a): shift down all elements of stack a by 1
// the last element becomes the first one

// rrb (reverse rotate b): shift down all elements of stack b by 1
// the last element becomes the first one


// rrr: rra and rrb at the same time