/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:55 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/03 13:50:06 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
sb (swap b): swap the first 2 elements at the top of stack b
do nothing if there is only one or no elements
*/

void	ft_sb(t_stack **b)
{
	t_stack	*second;

	if (!*b || !(*b)->next)
		return ;
	second = *b;
	*b = (*b)->next;
	second->next = (*b)->next;
	(*b)->next = second;  
}

// pb (push b): take the 1st element at the top of a and put it at the top of b
// do nothing if a is empty

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	//printf("pb: the start address of b: \t%p\n", *b);
	*b = *a;
	//printf("pb: the new address of b: \t%p\n", *b);
	//printf("pb: the start address of a: \t%p\n", *a);
	*a = (*a)->next;
	//printf("pb: the new address of a: \t%p\n", *a);
	(*b)->next = temp;
}

// rb (rotate b): shift up all elements of stack b by 1
// the first element becomes the last one

void	ft_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last_node;
	
	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	last_node = ft_last_element_list(*b);
	last_node->next = temp;
	temp->next = NULL;	
}

/*
 rrb (reverse rotate b): shift down all elements of stack b by 1
 the last element becomes the first one
*/

void	ft_rrb(t_stack **b)
{
	t_stack	*temp;
	int		i;

	i = 0;
	temp = *b; // 5850
	while ((*b)->next)
	{
		*b = (*b)->next; // 5820
		i++;
	}
	(*b)->next = temp; 
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
}
