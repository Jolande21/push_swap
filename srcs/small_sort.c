/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:05:28 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/05 17:21:54 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	max_index_position(t_stack **a, int size)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = *a;
	while (position < size)
	{
		printf("the current->index: %d\n", current->index);
		if (current->index == (size - 1))
			break;
		position++;
		current = current->next;
	}
	return (position);
}

static int	get_min_index(t_stack *a)
{
	t_stack	*current;
	int		min;

	current = a;
	min = INT_MAX;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	//printf("the min value in the small sort function: %d\n", min);
	return (min);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	position;

	position = max_index_position(a, 5);
	printf("the position value in sort_5: %d\n", position);
	if (position == 1)
		ft_ra(a);
	else if (position == 2)
	{
		ft_ra(a);
		ft_ra(a);
	}
	else if (position == 3)
	{
		ft_rra(a);
		ft_rra(a);
	}
	else if (position == 4)
		ft_rra(a);
	ft_pb(a, b);
	sort_4(a, b);
	ft_pa(a, b);
	ft_ra(a);
}

void	sort_4(t_stack **a, t_stack **b)
{
	int		position;

	position = max_index_position(a, 4);
	printf("the position value in sort_4: %d\n", position);
	if (position == 0 && ft_is_sorted(*a))
	{
		ft_ra(a);
		return ;
	}
	if (position == 1)
		ft_ra(a);
	else if (position == 2)
	{
		ft_ra(a);
		ft_ra(a); 
	}
	else if (position == 3)
		ft_rra(a);
	ft_pb(a, b);
	print_stack(*b);
	print_stack(*a);
	sort_3(a);
	ft_pa(a, b);
	ft_ra(a);
}

void	sort_3(t_stack **a)
{
	int		min;
	
	printf("the address of the head: %p\t and the value: %d\n", *a, (*a)->value);
	if (ft_is_sorted(*a))
		return ;
	min = get_min_index(*a);
	if ((*a)->index < (*a)->next->index && (*a)->index == min)
	{
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->index < (*a)->next->index)
		ft_rra(a);
	else if ((*a)->next->index == min)
	{
		if ((*a)->index == (*a)->next->index + 1)
			ft_sa(a);
		else
			ft_ra(a);
	}
	else
	{
		ft_sa(a);
		ft_rra(a);
	}
}

void	sort_small_list(t_stack **a, int size)
{
	t_stack	*b;

	b = NULL;
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, &b);
	else if(size == 5)
		sort_5(a, &b);
	print_stack(*a);
}