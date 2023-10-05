/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:27:34 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/05 16:57:42 by jolandestee      ###   ########.fr       */
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

// initializes the linked list for stack a 
t_stack	*init_stack(int argc, char **argv);

// check if the created linked list for stack a, is sorted
int	ft_is_sorted(t_stack *a);
int	list_size(t_stack *a);

// linked lists useful functions
t_stack	*ft_last_element_list(t_stack *a);
t_stack	*ft_create_list_element(int number);
void	ft_add_element_list_end(t_stack **a, t_stack *new_element);
void	print_stack(t_stack *stack);

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


// function to create an index of the elements in the linked list
int	index_stack(t_stack **a);

// conversion index to binary 
void			binary_index(t_stack *a);
unsigned int	int_to_bin(unsigned int nbr);

// radix functions
void	sort_big_list(t_stack *head);
void	radix(t_stack *a, int max_bits);

// functions to sort a small list
void	sort_small_list(t_stack **a, int size);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);

#endif