/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 16:53:03 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/12 11:33:24 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <limits.h>

long	ft_atoi(const char *str)
{
	long	i;
	long	nbr;
	int		sign;

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
		printf("%li\n", nbr);
		i++;
	}
	return (nbr * sign);
}

int	main(void)
{
	printf("ok\n");

	// how does it convert 0? 
	printf("the number created: %li\n", ft_atoi("0"));

	// Number > Maximum value for a variable of type int (2,147,483,647)
	printf("the number created: %li\n", ft_atoi("2147483648"));
	
	// Number < Minimum value for a variable of type int (-2,147,483,648)
	printf("the number created: %li\n", ft_atoi("-2147483648"));
	return (0);
}