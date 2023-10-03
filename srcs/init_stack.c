/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/03 13:51:15 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// t_stack	*init_linked_list(char *split)
// {
// 	t_stack	*new;
// 	int		number;
	
// 	number = ft_atoi(split);
// 	new = ft_create_list_element(number);
// 	return (new);
// }

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*new_element;
	char	**split;
	int		number;
	int		i;


	// if the number of arguments = 2
	split = NULL;
	if (ac == 2)
	{
		split = ft_split(av[1], ' ');
		if (!split)
			return (NULL);
		i = 0;
		a = NULL;
		while (split[i])
		{
			// convert the ascii number stored in temp to an int 
			number = ft_atoi(split[i]);

			// create a new element to store in the stack
			new_element = ft_create_list_element(number);
			if (!new_element)
				return (NULL);
			//printf("newly created element: %d\n", new->value);

			// add the newly created element to the list
			ft_add_element_list_end(&a, new_element);
			i++;
		}
	}
	else
	{
		i = 1;
		a = NULL;
		while (av[i])
		{
			// convert the ascii number stored in temp to an int 
			number = ft_atoi(av[i]);

			// create a new element to store in the stack
			new_element = ft_create_list_element(number);
			if (!new_element)
				return (NULL);
			//printf("newly created element: %d\t", new->value);
			//printf("the address: %p\n", new);

			// add the newly created element to the list
			ft_add_element_list_end(&a, new_element);
			i++;
		}
	}
	return (a);
}
