/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 15:48:43 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/14 12:29:53 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
ss: sa and sb at the same time
*/

void	ft_ss(t_stack **a, t_stack **b)
{
	ft_sa(a);
	ft_sb(b);
}


// rr: ra and rb at the same time
void	ft_rr(t_stack **a, t_stack **b)
{
	ft_ra(a);
	ft_rb(b);
}

// rrr: rra and rrb at the same time

void	ft_rrr(t_stack **a, t_stack **b)
{
	ft_rra(a);
	ft_rrb(b);
}