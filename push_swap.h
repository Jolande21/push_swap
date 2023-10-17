/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jolandesteenput <jolandesteenput@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:27:34 by jolandestee       #+#    #+#             */
/*   Updated: 2023/10/17 18:34:39 by jolandestee      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------------- ADDITIONAL LIBS ------------------------------------*/

# include "libft/libft.h"
# include <stdlib.h>

/*---------------------------- STRUCTURE -------------------------------------*/

typedef struct s_stack 
{
	int				value;
	int				index;
	struct s_stack	*next;
}	t_stack;

/*---------------------------- FUNCTIONS -------------------------------------*/

// checks to be done on the arguments
int				check_args(int argc, char **argv);

// initializes the linked list for stack a 
int				init_stack(int argc, char **argv, t_stack **a);

// utils functions for linked lists
int				ft_list_size(t_stack *a);
t_stack			*ft_last_element_list(t_stack *a);
t_stack			*ft_create_list_element(int number);
void			ft_add_element_list_end(t_stack **a, t_stack *new_element);

// utils for other functionalities
void			ft_error(char *message);
void			ft_free(char **array);
void			ft_free_stack(t_stack **stack);
int				get_min_index(t_stack *a);
unsigned int	int_to_bin(unsigned int nbr);

// instructions to sort stack a and stack b
void			ft_sa(t_stack **a);
void			ft_pa(t_stack **a, t_stack **b);
void			ft_ra(t_stack **a);
void			ft_rra(t_stack **a);
void			ft_sb(t_stack **b);
void			ft_pb(t_stack **a, t_stack **b);
void			ft_rb(t_stack **b);
void			ft_rrb(t_stack **b);
void			ft_ss(t_stack **a, t_stack **b);
void			ft_rr(t_stack **a, t_stack **b);
void			ft_rrr(t_stack **a, t_stack **b);

// function to create an index in ascending order for each element/node
int				init_index_stack(t_stack **a);

// general sorting functions 
void			init_sorting(t_stack **a, t_stack **b);
int				is_sorted(t_stack **a);

// functions to sort a big list (size > 5)
void			sort_big_list(t_stack **a, t_stack **b);

// functions to sort a small list
void			sort_small_list(t_stack **a, t_stack **b, int size);
void			sort_3(t_stack **a);
void			sort_4(t_stack **a, t_stack **b, int min);
void			sort_5(t_stack **a, t_stack **b);

#endif