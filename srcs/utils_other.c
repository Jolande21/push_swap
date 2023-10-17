/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:38 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/17 12:37:04 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_error(char *message)
{
	ft_putendl_fd(message, 2);
	exit(1);
}

void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
		i++;
	while (i >= 0)
	{
		free(array[i]);
		i--;
	}
}

void	ft_free_stack(t_stack **stack)
{
	t_stack	*to_delete;

	while (*stack)
	{
		to_delete = *stack;
		*stack = (*stack)->next;
		free(to_delete);
	}
	free(stack);
}

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

int	get_min_index(t_stack *a)
{
	t_stack	*current;
	int		min;

	current = a;
	min = 2147483647;
	while (current)
	{
		if (current->index < min)
			min = current->index;
		current = current->next;
	}
	return (min);
}
