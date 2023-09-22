/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/22 11:54:06 by jolandestee      ###   ########.fr       */
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

void	print_stack(t_stack *stack)
{
	t_stack	*current;

	current = stack;
	while (current)
	{
		printf("value: %d\t index: %d\t bin_index: %d\t array: %s\n", current->value, current->index, current->index_bin, current->bin_array);
		current = current->next;
	}
	printf("\n");
}

void	init_bin_array(t_stack *head)
{
	t_stack	*current;
	int		max_bits;
	int		max_index;
	
	// count the number of bits in the max index
	current = head;
	//printf("----------------the binary array created:-------------------\n");
	while (current)
	{
		current->bin_array = ft_itoa(current->index_bin);
		current = current->next;
	}
	//print_stack(head);

	// get the size of the list
	//printf("start init_bin_array OK\n");
	max_index = list_size(head) - 1;
	//printf("the max index in stack a: %d\n", max_index);

	// count the number of bits in the max index
	max_bits = 0;
	current = head;
	while (current)
	{
		if (current->index == max_index)
			max_bits = ft_strlen(current->bin_array);
		current = current->next;
	}
	//printf("the max number of bits to check: %d\n", max_bits);
	
	// push the elements from stack a to be
	push(head, max_bits);
}


void	push(t_stack *a, int max_bits)
{
	t_stack	*b;
	t_stack *current;
	int		max_index;
	int		i;
	//int		check;

	//printf("----------------the push function:-------------------\n");	
	
	b = NULL;
	i = 0;
	while (i < max_bits)
	{
		if (i > 0)
		{
			current = a;
			while (current)
			{
				current->index = current->index>>1;
				current->index_bin = int_to_bin(current->index);
				current = current->next;
			}
		}
		// printf("--the stack a after moving bit i:---\n");
		// print_stack(a);
		max_index = list_size(a);
		while (max_index)
		{
			if ((a->index_bin) % 10 == 0)
			{
				ft_pb(&a, &b);
				write(1,"pb\n", 3);
			}
			else
			{
				ft_ra(&a);
				write(1,"ra\n", 3);
			}
			max_index--;
		}
		// printf("the stacks after the inner while loop:\n");
		// print_stack(b);
		// print_stack(a);
		while (b)
		{
			ft_pa(&a, &b);
			write(1, "pa\n", 3);
		}
		// printf("the stacks after pushing everything to a again:\n");
		// print_stack(b);
		// print_stack(a);
		i++;
	}
	// check = ft_is_sorted(a);
	// if (!check)
	// 	printf("the stack is sorted!");
	// else
	// 	printf("the stack is not sorted!!");
}
