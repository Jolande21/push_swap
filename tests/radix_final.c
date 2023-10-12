/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_final.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 16:01:37 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 16:02:41 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
	
	// push the elements from stack a to b
	radix(head, max_bits);
}

void	radix(t_stack *a, int max_bits)
{
	t_stack	*b;
	t_stack *current;
	int		i;
	int		size;
	
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
		size = list_size(a);
		while (size) // check for every element of the list
		{
			if ((a->index_bin) % 10 == 0)
				ft_pb(&a, &b);
			else
				ft_ra(&a);
			size--;
		}
		while (b)
			ft_pa(&a, &b);
		i++;
	}
}
