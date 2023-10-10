/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:28:30 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 15:52:12 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"

void	ft_error(char *s)
{
	printf("%s\n", s);
	exit(1);
}

int duplicate(int num, char **args, int position)
{
	int	i;

	i = 0;
	while (args[i])
	{
		if (num == ft_atoi(args[i]) && i != position)
			return (1);
		i++;
	}
	return (0);
}


int	ft_is_num(char *num)
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

int	main(int argc, char **argv)
{
	char	**args;
	int		number;
	int		i;

	i = 0;
	args = NULL;
	if (argc == 2)
	{
		printf("the number of args is 2.\n");
		args = ft_split(argv[1], ' ');
		if (!args)
			return (0);
		while (args[i])
		{
			printf("%s\n", args[i]);
			i++;
		}
	}
	else
	{
		i = 1;
		args = argv;
	}
	while (args[i])
	{
		// convert the ascii number stored in temp to an int
		if (!ft_is_num(args[i]))
		{
			printf("this is not an int number.\n");
			exit(1);
		}
		number = ft_atoi(args[i]);
		printf("%d\n", number);
		if (duplicate(number, args, i))
			ft_error("the are duplicates.");
		i++;
	}
	// I need to free on 2 levels??
	//free(args);
	return (0);
}