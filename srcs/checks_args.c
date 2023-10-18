/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:02:17 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/17 18:34:32 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static int	duplicate(long number, char **args, int position)
{
	int	i;

	i = 1;
	while (args[i])
	{
		if ((ft_atoi(args[i]) == number) && (i != position))
			return (1);
		i++;
	}
	return (0);
}

static int	ft_is_num(char *num)
{
	int	i;

	i = 0;
	if (num[0] == '-')
		i++;
	if (!num[i])
		return (0);
	while (num[i])
	{
		if (!ft_isdigit(num[i]))
			return (0);
		i++;
	}
	return (1);
}

static void	init_checks(int i, char **args, int argc)
{
	long	number;

	if (!ft_is_num(args[i]))
	{
		if (argc == 2)
			ft_free(args);
		ft_error("Error");
	}
	number = ft_atoi(args[i]);
	if (number < -2147483648 || number > 2147483647)
	{
		if (argc == 2)
			ft_free(args);
		ft_error("Error");
	}
	if (duplicate(number, args, i))
	{
		if (argc == 2)
			ft_free(args);
		ft_error("Error");
	}
}

int	check_args(int argc, char **argv)
{
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
		init_checks(i, args, argc);
		i++;
	}
	if (argc == 2)
		ft_free(args);
	return (1);
}
