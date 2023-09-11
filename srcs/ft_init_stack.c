/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:36:32 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/11 17:42:49 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack		*ft_init_stack(int argc, char **argv)
{
	t_stack	*a;
	char	**temp;
	int		i;
	
	if (argc == 2)
		temp = ft_split(argv[1], " ");
	i = 1;
	while (temp[i])
	{
		a = ft_atoi(temp[i]);
		ft_add_element_end();	
	}
	return (a)
}