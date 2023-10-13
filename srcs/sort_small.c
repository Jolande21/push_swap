/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:05:28 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/13 13:41:15 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	get_max_index_position(t_stack **a, int size)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = *a;
	while (position < size)
	{
		if (current->index == (size - 1))
			break ;
		position++;
		current = current->next;
	}
	return (position);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	position;

	position = get_max_index_position(a, 5);
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

	position = get_max_index_position(a, 4);
	if (position == 0 && is_sorted(a))
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
	sort_3(a);
	ft_pa(a, b);
	ft_ra(a);
}

void	sort_3(t_stack **a)
{
	int		min;

	if (is_sorted(a))
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

void	sort_small_list(t_stack **a, t_stack **b, int size)
{
	if (size == 2)
		ft_sa(a);
	else if (size == 3)
		sort_3(a);
	else if (size == 4)
		sort_4(a, b);
	else if (size == 5)
		sort_5(a, b);
}
