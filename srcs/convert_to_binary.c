/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_to_binary.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 11:51:10 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/03 15:36:16 by jolandestee      ###   ########.fr       */
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

// this function sets the index of each element in the linked list 
// in binairy format

void	binary_index(t_stack *a)
{
	t_stack			*current;

	printf("----------------stack a after creating binary index:----------------\n");
	// update the binary index
    // what about the int type -> check unsigned or just int?
	current = a;
	while (current)
	{
		current->index_bin = int_to_bin(current->index);
		current = current->next;
	}
	print_stack(a);
}