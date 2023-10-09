/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/09 17:32:56 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*new_element;
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

		// create a new element to store in the stack
		new_element = ft_create_list_element(number);
		if (!new_element)
			return (NULL);

		// add the newly created element to the list
		ft_add_element_list_end(&a, new_element);
		i++;
	}
	return (a);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	int		check;
	
	
	if (argc < 2)
		exit(1);

	// check arguments
	ft_check_args(argc, argv);
	
	// init stack a
	a = init_stack(argc, argv);
	if (!a)
		exit(1);
	//printf("stack a is created!\n");

	
	// checks to be done
	check = checks(&a);
	if (!check)
		exit(1);
	return (0); 
}
	// print the elements of the stack; the values and the initial index
	//t_stack	*head; // only used to print the stack 
	//head = a;
	//printf("----------------------the linked list in main:----------------------\n");
	//print_stack(head);