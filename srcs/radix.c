/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/15 12:55:58 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	get_maximum(t_stack **a)
{
	t_stack	*current;
	int		max;

	current = *a;
	max = current->value;
	while (current->next)
	{
		if (current->next->value > max)
			max = current->next->value;
		current = current->next;
	}
	printf("the max int in the set: %d\n", max);
	return (max);
}

int	sorting(t_stack	*a)
{
	
}