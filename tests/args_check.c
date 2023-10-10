/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 11:28:30 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 11:42:08 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../libft/libft.h"

void	ft_error(void)
{
	write(1, "Error\n", 6);
	exit(1);
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
		i++;
	}
	// I need to free on 2 levels??
	//free(args);
	return (0);
}