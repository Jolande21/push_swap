/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:35:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/05 16:50:56 by jolandestee      ###   ########.fr       */
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
	write(1, "sa\n", 3);
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
	write(1, "pa\n", 3);
}

// ra (rotate a): shift up all elements of stack a by 1
// the first element becomes the last one

void	ft_ra(t_stack **a)
{
	t_stack	*last_node;
	t_stack *temp;
	
	if (!*a)
		return ;
	temp = *a; // 6810
	*a = (*a)->next; // 6830
	last_node = ft_last_element_list(*a); //68f0 
	last_node->next = temp; // 6810
	temp->next = NULL;
	write(1, "ra\n", 3); 
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
	temp = *a; // 5850
	while ((*a)->next)
	{
		*a = (*a)->next; // 5820
		i++;
	}
	(*a)->next = temp; 
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rra\n", 4);
}
