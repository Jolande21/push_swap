/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:27:34 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/19 12:05:24 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------------- ADDITIONAL LIBS ---------------------------------------*/

# include "../libft/libft.h"
# include <stdio.h> // delete at the end !!!
# include <stdlib.h>
# include <limits.h> // delete after use !! to find the min value

/*---------------------------- STRUCTURE ---------------------------------------*/

typedef struct s_stack 
{
	int				value;
	int				index;
	unsigned int	index_bin;
	struct s_stack	*next;
} t_stack;

/*---------------------------- FUNCTIONS ---------------------------------------*/

// create the linked list for stack a 
t_stack	*init_stack(int argc, char **argv);

// check if the created linked list for stack a, is sorted
int	ft_is_sorted(t_stack *a);
int	list_size(t_stack *a);

// returns the last node of the list
t_stack	*ft_last_list(t_stack *a);

// instructions 
void	ft_sa(t_stack **a);
void	ft_pa(t_stack **a, t_stack **b);
void	ft_ra(t_stack **a);
void	ft_rra(t_stack **a);
void	ft_sb(t_stack **b);
void	ft_pb(t_stack **a, t_stack **b);
void	ft_rb(t_stack **b);
void	ft_rrb(t_stack **b);
void	ft_ss(t_stack **a, t_stack **b);
void	ft_rr(t_stack **a, t_stack **b);
void	ft_rrr(t_stack **a, t_stack **b);

// radix functions
int	get_maximum(t_stack *a);

// index functions
int	index_stack(t_stack **a);

// conversion index to binary 
void	binary_index(t_stack *a);


#endif