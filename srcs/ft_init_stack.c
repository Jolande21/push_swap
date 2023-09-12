/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/12 11:53:38 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*ft_last_list(t_stack *a)
{
	t_stack *temp;

	temp = a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}


void	ft_add_element_end(t_stack **a, t_stack *new_element)
{
	t_stack	*former_last;
	
	if (!new_element)
		return ;
	if (*a == NULL)
		*a = new_element;
	else
	{
		// get the address of the last element of the stack
		former_last = ft_last_list(*a);

		// give the next pointer of the former last element, the address of
		// the newly created element of the list
		former_last->next = new_element;
	}	
}

t_stack	*ft_create_list_element(int number)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (NULL);
	new_element->value = number;
	new_element->next = NULL;
	return (new_element);
}


t_stack	*ft_init_stack(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*new;
	char	**temp;
	int		number;
	int		i;
	
	temp = NULL;
	if (argc == 2)
	{
		temp = ft_split(argv[1], ' ');
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
			printf("newly created element: %d\n", new->value);

			// add the newly created element to the list
			ft_add_element_end(&a, new);
			i++;	
		}
	}
	else
	{
		i = 1;
		a = NULL;
		while (argv[i])
		{
			// convert the ascii number stored in temp to an int 
			number = ft_atoi(argv[i]);

			// create a new element to store in the stack
			new = ft_create_list_element(number);
			printf("newly created element: %d\n", new->value);

			// add the newly created element to the list
			ft_add_element_end(&a, new);
			i++;
		}
	}
	printf("OK till here at the end of the init_stack function.\n");
	return (a);
}
