/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 17:27:34 by jolandestee       #+#    #+#             */
/*   Updated: 2023/09/12 10:26:49 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

/*----------------------- ADDITIONAL LIBS ---------------------------------------*/

# include "../libft/libft.h"
# include <stdio.h> // delete at the end !!!
# include <stdlib.h>

/*---------------------------- STRUCTURE ---------------------------------------*/

typedef struct s_stack 
{
    int             value;
    struct s_stack  *next;
} t_stack;

/*---------------------------- FUNCTIONS ---------------------------------------*/

t_stack *ft_init_stack(int argc, char **argv);

#endif