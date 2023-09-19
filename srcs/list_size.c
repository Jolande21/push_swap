/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 13:58:51 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/19 12:01:14 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	list_size(t_stack *a)
{
	int	count;

	count = 0;
	//printf("list_size: the address of 1st node: %p\n", a);
	while (a)
	{
		count++;
		a = a->next;
		//printf("list_size: the address of the next node: %p\n", a);
	}
	return (count);
}