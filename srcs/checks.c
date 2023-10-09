/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 10:55:56 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/09 17:43:47 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_sorted(t_stack **a)
{
	t_stack	*current;

	current = *a;
	//printf("the address of the first node: %p\n", current);
	while (current && current->next)
	{
		// check if the value (number) of the current element of the list
		// if it is greater than the value of the next number
		// then the list is not sorted
		//printf("the current element's value: %d\n", current->value);
		if (current->value > current->next->value)
			return (0);
		//printf("the address of the next node: %p\n", current->next);
		current = current->next;
	}
	return (1);
}

// check the size of the list
int	checks(t_stack **a)
{
	int	size;
	int	check;

	//printf("----------------------the size of the list:-------------------------\n");
	size = list_size(*a);
	if (size == 1)
	{
		write(1, "Error\n", 6);
		exit(1);
	}
	
	// check if the set of int values, is sorted
	if (!is_sorted(a))
	{
		//printf("the stack is not sorted.\n");
		// create an index of the int set in ascending order
		check = index_stack(a);
		if (!check)
		{
			printf("no indexation so the program stops here.\n");
			exit(1);
		}

		// sort the list based on the number of ints in the list = size
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
	else
	{
		printf("the stack is sorted!\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}

int	ft_check_args(int argc, char **argv)
{
	char	**args;
	int		number;
	int		i;

	i = 0;
	args = NULL;
	if (ac == 2)
	{
		args = ft_split(av[1], ' ');
		if (!args)
			return (NULL);
	}
	else
	{
		i = 1;
		args = av;
	}
	while (args[i])
	{
		// convert the ascii number stored in temp to an int 
		number = ft_atoi(av[i]);
		if (!ft_isdigit(args[i]))
			ft_error;
		i++;
	}
	return (a);
}

//printf("the number of elements in stack a: %d\n", size);