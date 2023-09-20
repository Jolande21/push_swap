/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/20 11:46:22 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	t_stack	*head;
	int		size;
	int		check;
	
	if (argc < 2)
		return (-1); // error function or do I need to use exit?

	// init stack a
	a = init_stack(argc, argv);
	if (!a)
		return (-1);
	printf("the stack is created!\n");

	// print the elements of the stack; the values and the initial index
	head = a;
	while (head)
	{
		printf("%d\t, index: %d\n", head->value, head->index);
		//printf("the address of the next node: %p\n", head->next);
		head = head->next;
	}
	printf("\n");

	// check if the list is sorted	
	size = list_size(a);
	printf("the number of elements in stack a: %d\n", size);

	// if the list is not sorted
	printf("the address of the first node: %p\n", a);
	if (!ft_is_sorted(a))
	{
		// print message
		printf("the stack is not sorted.\n");

		// look for the maximum int in the set of values
		get_maximum(a);

		// create an index of the int set in ascending order
		check = index_stack(&a);
		if (!check)
		{
			printf("no indexation so the program stops here.\n");
			return (-1);
		}
		else
		{
			// convert index to int binary
			binary_index(a);

			// store the bin index in char array
			init_bin_array(a); 
		}	

		// sort based on the size of the list 
		if (size <= 5)
			printf("This is a small array sort");
		// else
		// 	ft_sort(&a);
	}
	else
		printf("the stack is sorted!!\n");
	return (0); 
}