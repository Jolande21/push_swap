/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 11:05:28 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/04 18:36:57 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	printf("the min in the small sort function: %d\n", min);
	return (min);
}

static void	sort_3(t_stack **a)
{
	int		min;
	
	min = get_min_index(*a);
	if ((*a)->index < (*a)->next->index && (*a)->index == min)
	{
		ft_ra(a);
		ft_sa(a);
		ft_rra(a);
	}
	else if ((*a)->index < (*a)->next->index)
	{
		ft_rra(a);
		//printf("ft_rra\n");
	}
	else if ((*a)->next->index == min)
	{
		if ((*a)->index == (*a)->next->index + 1)
		{
			ft_sa(a);
			//printf("ft_sa\n");
		}
		else
		{	
			ft_ra(a);
			//printf("ft_ra\n");
		}
	}
	else
	{
		ft_sa(a);
		ft_rra(a);
		//printf("ft_sa && ft_rra\n");
	}
}
void	sort_small_list(t_stack **a, int size)
{
	if (size == 2)
	{
		printf("the size of the list is %d\n", size);
		ft_sa(a);
		write(1, "sa\n", 2);
	}
	else if (size == 3)
	{
		printf("the size of the list is %d\n", size);
		sort_3(a);
	}
	else if (size == 4)
		printf("the size of the list is %d\n", size);
	else if(size == 5)
		printf("the size of the list is %d\n", size);
	print_stack(*a);
}