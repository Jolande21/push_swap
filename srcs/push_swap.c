/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/18 11:28:06 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*head;
	int		size;
	
	if (argc < 2)
		return (-1); // error function or do I need to use exit?

	// init stack a
	a = init_stack(argc, argv);
	if (!a)
		return (-1);
	printf("the stack is created!\n");

	// print the elements of the stack
	head = a;
	while (head)
	{
		printf("%d\t, index: %d\n", head->value, head->index);
		head = head->next;
	}
	printf("\n");

	// check if the list is sorted	
	size = list_size(a);
	if (!ft_is_sorted(a))
	{
		printf("the stack is not sorted.\n");
		printf("the number of elements in stack a: %d\n", list_size(a));
		get_maximum(a);
		index_stack(&a);
		if (size <= 5)
			printf("This is a small array sort");
		// else
		// 	ft_sort(&a);
	}
	else
		printf("the stack is sorted!!\n");
	return (0); 
}