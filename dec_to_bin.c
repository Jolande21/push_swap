/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_to_bin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 17:53:11 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/18 21:47:13 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void    binaire_index(int num)
{
	int	base;
	int	i;
	int *binairy;

	base = 2;
	// divide the index by 2
	// stel = 8
	// 8 / 2 = 4 > 0 -> i = 1
	// 8 / 4 = 2 > 0 -> i = 2
	// 8 / 8 = 1 > 0 -> 3
	// 8 / 16 = 0 stop 
	i = 1; 
	while ((num / base) > 0)
    {
		i++;
        base *= 2;
	}
    // i = 4
    binairy = malloc(sizeof(char) * (i));
    if (!binairy)
        return ;

    // begin from the back
    // 5 hokjes: van 0 tem 4
    // stel i = 4 -> 4 -> NULL
    // 0  1  2  3
    // 1  0  0  0 
    i--;
    while (i >= 0)
    {
        binairy[i] = (num % 2); // 1 / 2 = 0 rem 1
        num = num / 2; // 1 
        i--; // 0
    }
    
    // print the binairy format of the decimal
    i = 0;
    while (i < 4)
    {
        printf("%d", binairy[i]);
        i++;
    }
    printf("\n");
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
    return (0);
}