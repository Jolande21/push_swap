/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/06 12:24:06 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	//t_stack	*head; // only used to print the stack 
	int		check;
	
	if (argc < 2)
		exit(1); // error function or do I need to use exit?

	// init stack a
	a = init_stack(argc, argv);
	if (!a)
		return (-1);
	//printf("the stack is created!\n");

	// print the elements of the stack; the values and the initial index
	//head = a;
	//printf("----------------------the linked list in main:----------------------\n");
	//print_stack(head);

	// check the size of the list
	//printf("----------------------the size of the list:-------------------------\n");
	int		size;
	size = list_size(a);
	//printf("the number of elements in stack a: %d\n", size);

	// check if list is sorted or not
	// if not sorted, check the size of the list
	if (!is_sorted(&a))
	{
		// print message
		//printf("the stack is not sorted.\n");

		// create an index of the int set in ascending order
		check = index_stack(&a);
		if (!check)
		{
			printf("no indexation so the program stops here.\n");
			return (-1);
		}

		// sort the list based on the number of ints in the list = size
		if (size <= 5)
			sort_small_list(&a, size);
		else
		{
			// convert created index to an int binary index
			binary_index(a);
			// sort the created binary index
			sort_big_list(a);			
		}
	}
	else
	{
		printf("the stack is sorted!\n");
		exit(EXIT_FAILURE);
	}
	return (0); 
}