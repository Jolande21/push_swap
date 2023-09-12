/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/12 11:06:39 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	
	if (argc < 2)
		return (-1); // error function or do I need to use exit?
	a = ft_init_stack(argc, argv);
	printf("the address stored in stack a: %p.\n", a);
	// if (!a)
	// 	return (-1);
	printf("the stack is created!\n");
	if (!ft_is_sorted(a))
	{
		printf("the stack is not sorted.\n");
		//ft_sort_stack(a);
	}
	else
		printf("the stack is sorted!!\n");
	return (0); 
}