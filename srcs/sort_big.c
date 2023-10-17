/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 12:45:02 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/17 13:12:15 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*

For radix sort, we need two boxes for 0 and 1 respectively. 
Here, A is box 1 and B is box 0. 
Then, we start from the rightmost bit to the leftmost bit.

At the i-th digit from the right, 
if the i-th digit from the top of A = 0 --> push to B
Else, ra to leave it in A. 

After we perform one operation on each number, 
each of them is in the box that corresponds to its digit, 
as how we put numbers in the boxes in radix sort.

*/

static void	radix(t_stack **a, t_stack **b, int max_bits)
{
	int				i;
	int				size;
	int				elements;
	unsigned int	binary;

	i = 0;
	size = ft_list_size(*a);
	while (i < max_bits)
	{
		elements = size;
		while (elements)
		{
			binary = int_to_bin(((*a)->index) >> i);
			if (binary % 10 == 0)
				ft_pb(a, b);
			else
				ft_ra(a);
			elements--;
		}
		while (*b)
			ft_pa(a, b);
		i++;
	}
}

void	sort_big_list(t_stack **a, t_stack **b)
{
	t_stack			*current;
	int				max_bits;
	int				max_index;
	unsigned int	max_index_bin;

	max_index = ft_list_size(*a) - 1; 
	max_bits = 0;
	max_index_bin = 0;
	current = *a;
	while (current)
	{
		if (current->index == max_index)
		{
			max_index_bin = int_to_bin(current->index);
			while (max_index_bin > 0)
			{
				max_bits++;
				max_index_bin = int_to_bin(max_index >> max_bits);
			}
		}
		current = current->next;
	}
	radix(a, b, max_bits);
}
