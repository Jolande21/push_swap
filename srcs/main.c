/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/10 18:04:02 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_sorting(t_stack **a)
{
	int	size;

	size = list_size(*a);
	if (size <= 5)
		sort_small_list(a, size);
	else
	{
		// convert created index to an int binary index
		binary_index(*a);
		// sort the created binary index
		sort_big_list(*a);
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	
	if (argc < 2)
		exit(1);
	if (!ft_check_args(argc, argv))
		exit(1);
	printf("OK\n");
	a = init_stack(argc, argv);
	if (!a)
		exit(1);
	list_checks(&a);
	if (!init_index_stack(&a))
		exit(1);
	init_sorting(&a);
	return (0); 
}
// print the elements of the stack; the values and the initial index
//printf("stack a is created!\n");
//t_stack	*head; // only used to print the stack 
//head = a;
//printf("----------------------the linked list in main:----------------------\n");
//print_stack(head);
// printf("OK\n");