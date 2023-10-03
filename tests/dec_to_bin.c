/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:53:11 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 10:38:40 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int	*binaire_index(int num)
{
	int	base;
	int	i;
	int *binairy;

	base = 2;
	i = 1; 
	while ((num / base) > 0)
	{
		i++;
		base *= 2;
	}    
	binairy = malloc(sizeof(char) * (i)); // maak 4 hokjes: van 0 tem 3;
	if (!binairy)
		return (0);
	while (i >= 0)
	{
		binairy[i] = (num % 2); // 1 / 2 = 0 rem 1
		num = num / 2; // 1 
		i--; // 0
	}
	return (binairy);
	
	// print the binairy format of the decimal
	// i = 0;
	// while (i < 4)
	// {
	//     printf("%d", binairy[i]);
	//     i++;
	// }
	// printf("\n");
}

int main(void)
{
	binaire_index(4);
	binaire_index(0);
	binaire_index(6);
	binaire_index(1);
	binaire_index(5);
	binaire_index(2);
	binaire_index(3);
	binaire_index(12);
	return (0);
}
	// divide the index by 2
	// stel = 8
	// 8 / 2 = 4 > 0 -> i = 1
	// 8 / 4 = 2 > 0 -> i = 2
	// 8 / 8 = 1 > 0 -> 3
	// 8 / 16 = 0 stop 