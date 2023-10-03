/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:53:03 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/03 13:41:33 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <limits.h>

int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	nbr;

	i = 0;
	nbr = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while ('0' <= str[i] && str[i] <= '9')
	{
		nbr = (str[i] - 48) + (nbr * 10);
		printf("%i\n", nbr);
		i++;
	}
	return (nbr * sign);
}

int	main(void)
{
	printf("ok\n");

	// how does it convert 0? 
	printf("the number created: %i\n", ft_atoi("0"));

	// Maximum value + 1 for variable of type int: 2,147,483,648
	printf("the number created: %i\n", ft_atoi("2147483647"));
	
	// Minimum value for a variable of type int: -2,147,483,648
	printf("the number created: %i\n", ft_atoi("-2147483648"));
	return (0);
}