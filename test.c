/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/15 16:35:26 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/15 16:42:45 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(void)
{
	int	num;

	num = 36;
	printf("Num = %d -> Move 2 bits: %d\n", num, num>>2);

	num = 8;
	printf("Num = %d -> Move 1 bit: %d\n", num, num>>1);

	num = 5;
	printf("Num = %d -> Move 2 bits: %d\n", num, num>>2);

	num = 2;
	printf("Num = %d -> Move 4 bits: %d\n", num, num>>4);

	num = 87;
	printf("Num = %d -> Move 3 bits: %d\n", num, num>>3);
	return (0);
}