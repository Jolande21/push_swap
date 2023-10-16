/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/16 10:02:06 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	init_stack(int argc, char **argv, t_stack **a)
{
	t_stack	*new_element;
	char	**args;
	int		i;

	i = 0;
	args = NULL;
	if (argc == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		new_element = ft_create_list_element(ft_atoi(args[i]));
		ft_add_element_list_end(a, new_element);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (1);
}
