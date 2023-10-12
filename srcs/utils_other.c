/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:38 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 17:17:42 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *message)
{
	int	i;
	
	write(1, "Error: ", 7);
	i = 0;
	while (message[i])
	{
		write(1, &message[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}
// converts an integer to binary

unsigned int	int_to_bin(unsigned int nbr)
{
	unsigned int	bin;
	
	if (nbr == 0)
		return (0);
	if (nbr == 1)
		return (1);
	bin = (nbr % 2) + 10 * int_to_bin(nbr / 2);
	return (bin);	
}

int	get_max_index_position(t_stack **a, int size)
{
	t_stack	*current;
	int		position;

	position = 0;
	current = *a;
	while (position < size)
	{
		if (current->index == (size - 1))
			break;
		position++;
		current = current->next;
	}
	return (position);
}

int	get_min_index(t_stack *a)
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
	return (min);
}