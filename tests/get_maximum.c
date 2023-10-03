/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_maximum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/22 10:46:51 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/22 10:47:03 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
int	get_maximum(t_stack *a)
{
	t_stack	*current;
	int		max;

	current = a;
	//printf("the first value to check in get_max: %d\n", current->value);
	max = current->index;
	
	//printf("the address of the next node: %p\n", current->next);
	while (current)
	{
		//printf("the next value to check: %d\n", current->next->value);
		if (current->index > max)
			max = current->index;
		current = current->next;
	}
	printf("the max index in the set: %d\n", max);
	return (max);
}

*/