/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:09 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 16:14:31 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"

unsigned int	int_to_int(unsigned k) 
{
	unsigned int bin;

	if (k == 0) 
		return 0;
	if (k == 1) 
		return 1;
	bin = (k % 2) + 10 * int_to_int(k / 2);
	return (bin);
}

int	main(int ac, char **av)
{
	char			*binary;
	unsigned int	bin_index;
	int				nbr;
	int				i;
	int				j;
	
	if (ac < 2)
		return (-1);
		
	// loop through all args 
	i = 1;
	while (av[i])
	{
		// convert args in ints
		nbr = ft_atoi(av[i]);	

		// convert ints in binary numbers
		bin_index = int_to_int(nbr);
		
		// print the converted numbers 
		printf("%d in binary: %d -- ", nbr, bin_index);

		// convert bin into char 
		binary = ft_itoa(bin_index);
	
		// print the char * array where bin is located 
		j = 0;
		printf("binary array: ");
		while (binary[j])
			printf("%c", binary[j++]);
		printf("\n");
		
		// free the binary index created
		free (binary);
		
		// go to the next arg
		i++;
	}
	
	// end 
	return (0);
}

//  printf("%d\n", int_to_int(4));
// 	printf("%d\n", int_to_int(0));
// 	printf("%d\n", int_to_int(6));
// 	printf("%d\n", int_to_int(1));
// 	printf("%d\n", int_to_int(5));
// 	printf("%d\n", int_to_int(2));
// 	printf("%d\n", int_to_int(3));
// 	printf("%d\n", int_to_int(12));
// 	printf("%d\n", int_to_int(36));