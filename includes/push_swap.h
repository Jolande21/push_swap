/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:27:34 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/12 13:40:58 by jsteenpu         ###   ########.fr       */
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

// checks to be done on the args
int	check_args(int argc, char **argv);

// initializes the linked list for stack a 
t_stack	*init_stack(int argc, char **argv);

// utils for linked lists
int		list_size(t_stack *a);
t_stack	*ft_last_element_list(t_stack *a);
t_stack	*ft_create_list_element(int number);
void	ft_add_element_list_end(t_stack **a, t_stack *new_element);
void	print_stack(t_stack *stack);

// utils for other functionalities
void	ft_error(char *message);

// instructions to sort stack a and stack b
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
int	init_index_stack(t_stack **a);

// conversion index to binary 
void			binary_index(t_stack *a);
unsigned int	int_to_bin(unsigned int nbr);

// general sorting functions 
void	init_sorting(t_stack **a);
int		is_sorted(t_stack **a);

// functions to sort a big list
void	sort_big_list(t_stack *head);
void	radix(t_stack *a, int max_bits);

// functions to sort a small list
void	sort_small_list(t_stack **a, int size);
void	sort_3(t_stack **a);
void	sort_4(t_stack **a, t_stack **b);

#endif