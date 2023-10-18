/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:34:01 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/17 11:41:25 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	**a;
	t_stack	**b;

	if (argc < 2)
		exit (1);
	if (!check_args(argc, argv))
		exit(1);
	a = (t_stack **)malloc(sizeof(t_stack));
	b = (t_stack **)malloc(sizeof(t_stack));
	if (!a || !b)
		exit(1);
	*a = NULL;
	*b = NULL;
	if (!init_stack(argc, argv, a))
		exit(1);
	init_sorting(a, b);
	ft_free_stack(a);
	ft_free_stack(b);
	exit (0);
}
