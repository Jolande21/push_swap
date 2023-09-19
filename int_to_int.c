/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_to_int.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 10:22:09 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 10:41:47 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

unsigned	int_to_int(unsigned k) 
{
	unsigned int bin;

	if (k == 0) 
		return 0;
	if (k == 1) 
		return 1;
	bin = (k % 2) + 10 * int_to_int(k / 2);
	return (bin);
}

int main(void)
{
	printf("%d\n", int_to_int(8));
	printf("%d\n", int_to_int(4));
	printf("%d\n", int_to_int(0));
	printf("%d\n", int_to_int(6));
	printf("%d\n", int_to_int(1));
	printf("%d\n", int_to_int(5));
	printf("%d\n", int_to_int(2));
	printf("%d\n", int_to_int(3));
	printf("%d\n", int_to_int(12));
	printf("%d\n", int_to_int(20));
	return (0);
}