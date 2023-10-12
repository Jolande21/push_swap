/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_binary_index.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:10 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/12 14:38:20 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// function to convert the int index to binary

unsigned int	int_to_bin(unsigned int nbr)
{
	unsigned int	bin;
	
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	bin = (nbr % 2) + 10 * int_to_bin(nbr / 2 );
	return (bin);	
}

// sets the index of each element in the linked list 
// in binairy format

void	binary_index(t_stack *a)
{
	t_stack			*current;

	current = a;
	while (current)
	{
		current->index_bin = int_to_bin(current->index);
		current = current->next;
	}	
}
