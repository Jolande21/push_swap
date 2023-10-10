/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/10 18:05:37 by jsteenpu         ###   ########.fr       */
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
	a = NULL;
	while (args[i])
	{
		printf("OK end\n");
		number = ft_atoi(av[i]);
		new_element = ft_create_list_element(number);
		if (!new_element)
			return (NULL);
		ft_add_element_list_end(&a, new_element);
		i++;
	}
	return (a);
}
//printf("newly created element: %d\t", new->value);
//printf("the address: %p\n", new);
// t_stack	*init_linked_list(char *split)
// {
// 	t_stack	*new;
// 	int		number;
	
// 	number = ft_atoi(split);
// 	new = ft_create_list_element(number);
// 	return (new);
// }