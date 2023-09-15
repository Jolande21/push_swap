/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/15 15:59:17 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack *a;
	
	if (argc < 2)
		return (-1); // error function or do I need to use exit?
	a = init_stack(argc, argv);
	if (!a)
		return (-1);
	printf("the stack is created!\n");
	if (!ft_is_sorted(a))
	{
		printf("the stack is not sorted.\n");
		printf("the number of elements in stack a: %d\n", list_size(a));
		printf("the address stored in a: %p\n", a);
		get_maximum(a);
	}
	else
		printf("the stack is sorted!!\n");
	return (0); 
}