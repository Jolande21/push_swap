/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions_b.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 16:39:55 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/13 13:03:35 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	write(1, "sb\n", 3);
}

// pb (push b): take the 1st element at the top of a and put it at the top of b
// do nothing if a is empty

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack	*temp;

	if (!*a)
		return ;
	temp = *b;
	*b = *a;
	*a = (*a)->next;
	(*b)->next = temp;
	write(1, "pb\n", 3);
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
	write(1, "rb\n", 3);
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
	temp = *b;
	while ((*b)->next)
	{
		*b = (*b)->next;
		i++;
	}
	(*b)->next = temp; 
	while (i > 1)
	{
		temp = temp->next;
		i--;
	}
	temp->next = NULL;
	write(1, "rrb\n", 4);
}
