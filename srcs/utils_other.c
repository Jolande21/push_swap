/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_other.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:40:38 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/10/10 14:56:33 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_error(char *message)
{
	int	i;
	
	write(1, "Error: ", 7);
	i = 0;
	while (message[i])
	{
		write(1, &message[i], 1);
		i++;
	}
	write(1, "\n", 1);
	exit(0);
}