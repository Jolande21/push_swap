/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
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
	int		max_index_bin;
	
	// look for the max index = the size of the list - 1 
	max_index = list_size(head) - 1;

	// count the number of bits in the max index
	max_bits = 0;
	max_index_bin = 0;
	current = head;
	while (current)
	{
		if (current->index == max_index)
		{
			max_index_bin = current->index_bin;
			while (max_index_bin > 0)
			{
				max_bits++;
				max_index = max_index>>1;
				max_index_bin = int_to_bin(max_index);
			}
		}
		current = current->next;
	}
	printf("the max_bits: %d\n", max_bits);
	
	// push the elements from stack a to b
	radix(head, max_bits);
}

void	radix(t_stack *a, int max_bits)
{
	t_stack	*b;
	t_stack *current;
	int		max_index;
	int		i;
	int		size;

	printf("------------------------- radix function: --------------------------\n");	
	
	size = list_size(a);
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
		max_index = size;
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
		while (b)
		{
			ft_pa(&a, &b);
			write(1, "pa\n", 3);
		}
		i++;
	}
	print_stack(a);
}


//printf("the max index: %d\n", max_index);
//printf("the max index bin: %d\n", max_index_bin);
//printf("the max_bits: %d\n", max_bits);
//printf("the new max_index_bin: %d\n", max_index_bin);
//printf("start init_bin_array OK\n");
//printf("the max index in stack a: %d\n", max_index);

		// printf("--the stack a after moving bit i:---\n");
		// print_stack(a);
	// check = ft_is_sorted(a);
	// if (!check)
	// 	printf("the stack is sorted!");
	// else
	// 	printf("the stack is not sorted!!");
	// printf("the stacks after the inner while loop:\n");
	// print_stack(b);
	// print_stack(a);
	// print_stack(b);
	// printf("the stacks after pushing everything to a again:\n");
	// print_stack(a);