/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/12 13:20:38 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack	*init_stack(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*new_element;
	char	**args;
	int		number;
	int		i;

	i = 0;
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (NULL);
	}
	else
	{
		i = 1;
		args = argv;
	}
	a = NULL;
	while (args[i])
	{
		number = ft_atoi(args[i]);
		new_element = ft_create_list_element(number);
		if (!new_element)
			return (NULL);
		ft_add_element_list_end(&a, new_element);
		i++;
	}
	return (a);
}
