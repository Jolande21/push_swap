/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/19 19:35:03 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*

As in radix sort, we need two boxes for 0 and 1 respectively. 
Here we treat A as box 1 and B as box 0. 
Then, we start from the rightmost bit to the leftmost bit.

At the i-th digit from the right, 
if the i-th digit of the top number of A is 0, 
we perform pb to put this number in stack B. 
Else, we perform ra to leave it in stack A. 

After we perform one operation on each number, 
each of them is in the box that corresponds to its digit, 
as how we put numbers in the boxes in radix sort.

*/

int	get_maximum(t_stack *a)
{
	t_stack	*current;
	int		max;

	current = a;
	//printf("the first value to check in get_max: %d\n", current->value);
	max = current->value;
	
	//printf("the address of the next node: %p\n", current->next);
	while (current->next)
	{
		//printf("the next value to check: %d\n", current->next->value);
		if (current->next->value > max)
			max = current->next->value;
		current = current->next;
	}
	printf("the max int in the set: %d\n", max);
	return (max);
}

// this function will convert the int binary index into a char array
// this array stores the binary of index 

void	init_bin_array(t_stack *head)
{
	t_stack	*current;
	char	**binary; // the 2D array that holds the address of all the binary index 
	int		i;
	int		size_a; // total #of elements in stack a 

	// allocate memory to store all the created binary arrays
	// the size of this 2d array is equal to the number of elements in the stack
	//size_a = (ft_last_list(head)->index) +  1;
	size_a = list_size(head);
	
	binary = (char **)malloc(sizeof(char *) * (size_a + 1));
	if (!binary)
	{
		printf("malloc error in bin_to_array function.\n");
		return ;
	}
	printf("the size of the list: %d\n", size_a);
	// set the end of the 2D array
	binary[size_a] = NULL;

	// fill the 2D array with the address of each newly created bin array
	current = head;
	i = 0;
	while (i < size_a)
	{
		binary[i] = ft_itoa(current->index_bin);
		if (!binary[i])
			return ;
		printf("The address of the binary arrays: %p\n", binary[i]);
		current = current->next;
		i++;
	}
	
	// print all the binary arrays
	i = 0;
	printf("the created binary array:\n");
	while (binary[i])
	{
		printf("%s\n", binary[i]);
		i++;
	}
	push(head, binary);
}

// this function pushes all elements with ith digit == 0
// to stack b

// stack A is for 1 
// stack B is for 0

void	push(t_stack *a, char **bin_array)
{
	int		i;
	t_stack	*b;
	
	i = 0;
	b = NULL;
	while (bin_array[i])
	{
		if (bin_array[i][0] == '0')
		{
			ft_pb(&a, &b);
		}
		printf("the index in push loop: %i\n", i);
		i++;
	}

	// print stack b 
	i = 0;
	printf("this is the stack b:\n");
	while (b)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", b->value, b->index, b->index_bin);
		b = b->next;
	}
}