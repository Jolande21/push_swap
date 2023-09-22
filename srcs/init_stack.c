/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/22 11:50:33 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int ac, char **av)
{
	t_stack	*a;
	t_stack	*new;
	char	**temp;
	int		number;
	int		i;
	
	temp = NULL;
	if (ac == 2)
	{
		temp = ft_split(av[1], ' ');
		if (!temp)
			return (NULL);
		i = 0;
		a = NULL;
		while (temp[i])
		{
			// convert the ascii number stored in temp to an int 
			number = ft_atoi(temp[i]);

			// create a new element to store in the stack
			new = ft_create_list_element(number);
			//printf("newly created element: %d\n", new->value);

			// add the newly created element to the list
			ft_add_element_end(&a, new);
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
			new = ft_create_list_element(number);
			//printf("newly created element: %d\t", new->value);
			//printf("the address: %p\n", new);

			// add the newly created element to the list
			ft_add_element_end(&a, new);
			i++;
		}
	}
	return (a);
}
