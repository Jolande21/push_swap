/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/20 13:54:05 by jolandestee      ###   ########.fr       */
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

	current = head;
	while (current)
	{
		current->bin_array = ft_itoa(current->index_bin);
		//printf("The address of the binary arrays: %p\n", current->bin_array);
		current = current->next;
	}
	
	// print all the binary arrays
	current = head;
	printf("the created binary array:\n");
	while (current)
	{
		printf("%s\n", current->bin_array);
		current = current->next;
	}
	push(head);
}

// this function pushes all elements with ith digit == 0
// to stack b

// stack A is for 1 
// stack B is for 0
// hello -> ft_strlen = 5
// dus van 0 tem 4 

void	push(t_stack *a)
{
	t_stack	*b;
	t_stack	*current; // var to check the stack a after pb
	size_t	len;

	current = a;
	// CHECK: print stack a
	printf("this is the stack a before the push:\n");
	while (a)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", a->value, a->index, a->index_bin);
		a = a->next;
	}
	
	// push all elements of which the i-th digit is equal to '0' to b
	b = NULL;
	len = 0;
	
	while (current)
	{
		//printf("push: the address of the 1st node: %p\n", a);
		len = ft_strlen(current->bin_array);
		//printf("the length: %zu of the value to check: %c\n", len, a->bin_array[len - 1]);
		if (current->bin_array[len - 1] == '0')
		{
			//printf("the bin index pushed to b: %u\n", a->index_bin);
			ft_pb(&current, &b);
			//printf("the b stack: %u\n", b->index_bin);
		}
		else
			current = current->next;
		//printf("The address of the next node: %p\n", a->next);
	}

	// CHECK: print stack b
	printf("this is the stack b:\n");
	while (b)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", b->value, b->index, b->index_bin);
		b = b->next;
	}

	// CHECK: print stack a
	printf("this is the stack a after the push:\n");
	while (a)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", a->value, a->index, a->index_bin);
		a = a->next;
	}
}

// probleem: ik moet telkens naar het einde gaan van ieder array met de bin index om the least significant digit te vinden