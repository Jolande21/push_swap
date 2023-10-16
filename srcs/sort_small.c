/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:05:28 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/16 15:34:36 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_min_index_position(t_stack **a, int min)
{
	t_stack	*current;
	int		position;

	current = *a;
	position = 0;
	while (current)
	{
		if (current->index == min)
			break ;
		position++;
		current = current->next;
	}
	return (position);
}

void	sort_5(t_stack **a, t_stack **b)
{
	int	position;

	position = get_min_index_position(a, 0);
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
	if (is_sorted(a))
		return ;
	ft_pb(a, b);
	sort_4(a, b, 1);
	ft_pa(a, b);
}

void	sort_4(t_stack **a, t_stack **b, int min)
{
	int		position;

	position = get_min_index_position(a, min);
	if (position == 0 && is_sorted(a))
		return ;
	if (position == 1)
		ft_ra(a);
	else if (position == 2)
	{
		ft_ra(a);
		ft_ra(a); 
	}
	else if (position == 3)
		ft_rra(a);
	if (is_sorted(a))
		return ;
	ft_pb(a, b);
	sort_3(a);
	ft_pa(a, b);
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
		sort_4(a, b, 0);
	else if (size == 5)
		sort_5(a, b);
}
