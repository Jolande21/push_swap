/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_ps_prinft_checks.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/04 11:25:19 by jolandestee      ###   ########.fr       */
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

this function will convert the int binary index into a char array
this array stores the binary of index 
*/

void	sort_big_list(t_stack *head)
{
	t_stack	*current;
	int		max_bits;
	int		max_index;
	
	// count the number of bits in the max index
	current = head;
	printf("----------------the binary array created:-------------------\n");
	while (current)
	{
		current->bin_array = ft_itoa(current->index_bin);
		printf("index: %d\t bin_index: %d\t array: %s\n", current->index, current->index_bin, current->bin_array);
		current = current->next;
	}
	printf("OK\n");

	// get the size of the list
	printf("start init_bin_array OK\n");
	max_index = list_size(head) - 1;
	printf("the max index in stack a: %d\n", max_index);

	// count the number of bits in the max index
	max_bits = 0;
	current = head;
	while (current)
	{
		if (current->index == max_index)
			max_bits = ft_strlen(current->bin_array);
		current = current->next;
	}
	printf("the max number of bits to check: %d\n", max_bits);
	
	// push the elements from stack a to be
	push(head);
}


void	push(t_stack *a)
{
	t_stack	*b;
	t_stack *current; // var to print the status of each stack
	size_t	len;
	int		max_index;


	// get the size of the list
	printf("start init_bin_array OK\n");
	max_index = list_size(a);
	printf("the max index in stack a: %d\n", max_index);
	// push all elements of which the i-th digit is equal to '0' to b
	b = NULL;
	len = 0;
	while (max_index)
	{
		printf("push: the address of the 1st node: %p\n", a);
		len = ft_strlen(a->bin_array);
		//printf("the length: %zu of the value to check: %c\n", len, a->bin_array[len - 1]);
		if (a->bin_array[len - 1] == '0')
		{
			//printf("the bin index pushed to b: %u\n", a->index_bin);
			ft_pb(&a, &b);
			//printf("the b stack: %u\n", b->index_bin);
		}
		else
		{
			ft_ra(&a);
			printf("The address of the current node after ra: %p\n", a);
			printf("The address of the next node: %p\n", a->next);
			printf("The address of the new last node: %p\n", ft_last_list(a));
		}
		max_index--;
	}

	// CHECK: print stack b
	current = b;
	printf("this is the stack b:\n");
	while (current)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", current->value, current->index, current->index_bin);
		current = current->next;
	}

	// CHECK: print stack a
	current = a;
	printf("this is the stack a after the push:\n");
	while (current)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", current->value, current->index, current->index_bin);
		current = current->next;
	}
	
	// push everything back to stack a until b is empty
	while (b)
	{
		ft_pa(&a, &b);
	}

	// CHECK: print stack b
	current = b;
	printf("this is the stack b:\n");
	while (current)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", current->value, current->index, current->index_bin);
		current = current->next;
	}

	// CHECK: print stack a
	current = a;
	printf("this is the stack a after the push:\n");
	while (current)
	{
		printf("the value: %d\t the index: %d\t the binary index: %u\n", current->value, current->index, current->index_bin);
		current = current->next;
	}
}

// probleem: ik moet telkens naar het einde gaan van ieder array met de bin 
// index om the least significant digit te vinden


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

	// // CHECK: print stack a
	// printf("this is the stack a before the push:\n");
	// while (a)
	// {
	// 	printf("the value: %d\t the index: %d\t the binary index: %u\n", a->value, a->index, a->index_bin);
	// 	a = a->next;
	// }
	