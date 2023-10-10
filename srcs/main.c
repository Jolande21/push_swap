/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/10 12:57:36 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*a;
	
	if (argc < 2)
		ft_error("please provide a set of ints.");
	if (!ft_check_args(argc, argv))
		exit(1);
	a = init_stack(argc, argv);
	if (!a)
		exit(1);
	//printf("stack a is created!\n");
	if (!list_checks(&a))
		exit(1);
	return (0); 
}
// print the elements of the stack; the values and the initial index
//t_stack	*head; // only used to print the stack 
//head = a;
//printf("----------------------the linked list in main:----------------------\n");
//print_stack(head);