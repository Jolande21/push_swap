/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 11:12:00 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/18 14:55:47 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int get_minimum(t_stack **a)
{
    t_stack	*head;
    int		min_value; // Initialize to maximum possible value

	head = *a;
	min_value = INT_MAX;
    while (head)
    {
        if (head->value < min_value && head->index == -1)
        {
            min_value = head->value;
        }
        head = head->next;
    }
    return (min_value);
}

void	index_stack(t_stack **a)
{
    t_stack	*head;
    int		index;
	int		min_value1;
	int		min_value2;

	head = *a;
	index = -1;
	min_value1 = get_minimum(a); // 6
	min_value2  = min_value1; // 6
    while (head)
    {
		//printf("the min: %d\n", min_value1);
		if (head->value == min_value1 && head->index == -1)
		{
			// set the correct index
			//printf("the head value: %d\n", head->value);
			index++;
			head->index = index; // 0 -> 1
			// // get the new minimum value 
			min_value2 = get_minimum(a); // 38
			
			// // init the head back to the beginning of the list
			//head = *a; // Reset head to the beginning of the list
		}
		if (min_value1 != min_value2)
		{
			head = *a;
			min_value1 = min_value2;
		}
        else
			head = head->next;
    }
	
	// print the indexed list
	head = *a;
	while (head)
	{
		printf("%d\t, index: %d\n", head->value, head->index);
		head = head->next;
	}
	printf("\n");
}
// de functie sprint direct naar de volgende node ipv eerst node na het zoeken van een nieuw min



/*int	get_minimum(t_stack	**a)
{
	t_stack	*head;
	int		min_value;

	// init head
	head = *a;
	// printf("the address in of the head: %p\n", head);
	
	// // find the minimum value in the stack;
	// if (min_value == head->value && head->next)
	// 	min_value = head->next->value;
	// else
	// 	min_value = head->value;
	// if (head->index != -1 && head->next)
	// 		min_value = head->next->value;
	min_value = INT_MAX;
	while (head)
	{
		if (head->value < min_value && head->index == -1)
		{
			min_value = head->value;
			printf("the new min value: %d\n", min_value);
		}
		head = head->next;
	}
	printf("the min int in the set: %d\n", min_value);
	return (min_value);
}

void	index_stack(t_stack **a)
{
	t_stack	*head;
	int		index;
	int		min_value;

	// init head
	head = *a;
	
	// // find the initial minimum in the list --> 4 
	// min_value = head->value;
	// //min_value = get_minimum(a, min_value);
	// printf("the first minimum value in index stack: %d\n", min_value);

	// loop through the list to init the index
	index = -1;
	min_value = get_minimum(a);
	while (head)
	{
		// increase the index where the min is located
		// find the next min value
		
		if (head->value == min_value)
		{
			head->index = index++;
			printf("the new head index: %d\n", head->index);
			min_value = get_minimum(a);
			head = *a;
			// printf("the min value in the loop: %d\n", min_value);
			// printf("the address of head in the loop: %p\n", head);
		}
		head = head->next;
		printf("the new address of head in the loop: %p\n", head);
	}

	// print the indexed list
	head = *a;
	while (head)
	{
		printf("%d\t, index: %d\n", head->value, head->index);
		head = head->next;
	}
	printf("\n");
} */

