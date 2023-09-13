/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:39:12 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 11:55:55 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct t_stack {
    int data;
    struct t_stack *next;
} t_stack;

void	ft_pa(t_stack **a, t_stack **b)
{
	t_stack	*temp;
	
	if (!*b)
		return ;
	
	// store the head of a in temp
	temp = *a;
	
	// the element at the top of b -> is the head of the stack?
	// the head of a gets the address of the head of b
	*a = *b;

	// update the new head of b to point to the second node
	*b = (*b)->next;
	 
	// the *b address next needs to be updated with the address of the old next 1st node in a
	(*a)->next = temp;
}



// Function to push an element onto the stack
void	push(t_stack **stack, int value) 
{
    t_stack *new_node;
	
	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return ;
    new_node->data = value;
    new_node->next = *stack;
    *stack = new_node;
}

// Function to print the contents of a stack
void	print_stack(t_stack *stack) 
{
    while (stack != NULL) 
	{
        printf("%d ", stack->data);
        stack = stack->next;
    }
    printf("\n");
}

int	main(void) 
{
    t_stack *stack_a = NULL;
    t_stack *stack_b = NULL;

    // Push some elements onto stack B
    push(&stack_b, 7);
    push(&stack_b, 5);
    push(&stack_b, 2);
	push(&stack_a, 1);

    // Print the initial state of both stacks
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    // Perform the pa operation
    ft_pa(&stack_a, &stack_b);

    // Print the updated state of both stacks after the operation
    printf("Stack A: ");
    print_stack(stack_a);
    printf("Stack B: ");
    print_stack(stack_b);

    return 0;
}

