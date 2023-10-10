/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:02:17 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 15:58:59 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int	duplicate(int number, char **args, int position)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (ft_atoi(args[i]) == number && i != position)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_args(int argc, char **argv)
{
	char	**args;
	int		number;
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
		if (!ft_is_num(args[i]))
			ft_error("some arguments are not integers.");
		number = ft_atoi(args[i]);
		if (number < -2147483648 || number > 2147483647)
			ft_error("some arguments are bigger or smaller than an int.");
		if (duplicate(number, args, i))
			ft_error("there are duplicates.");
		i++;
	}
	return (1);
}
