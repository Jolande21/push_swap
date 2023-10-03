/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 10:55:20 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 14:54:40 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// pb (push b): take the 1st element at the top of a and put it at the top of b
// do nothing if a is empty

#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack 
{
    int             value;
    struct s_stack  *next;
} t_stack;

void	ft_pb(t_stack **a, t_stack **b)
{
	t_stack *temp;

	if (!*a)
		return ;
	printf("the address *b before: %p\n", *b);
	printf("the address *a before: %p\n", *a);
	temp = *b;
	*b = *a;
	printf("the address *b after: %p\n", *b);
	*a = (*a)->next;
	printf("the address *a after: %p\n", *a);
	(*b)->next = temp;
	printf("the address *b->next after: %p\n", (*b)->next);
}

void	ft_print_stack(t_stack *stack)
{
	while (stack)
	{
		printf("%d ", stack->value);
		stack = stack->next;
	}
	printf("\n");
}

void	ft_new_node(t_stack **stack, int number)
{
	t_stack	*new;

	new = (t_stack *)malloc(sizeof(t_stack));
	if (!new)
		return ;
	//printf("the address of the new node: %p\n", new);
	new->value = number;
	//printf("the new value: %d\n", new->value);
	//printf("the address stored in *stack assigned to new: %p\n", *stack);
	new->next = *stack;
	*stack = new;
	//printf("the new address of *stack: %p\n", *stack);
}


int	main(void)
{
	t_stack *stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	
	// print the address of stack a and stack b
	printf("stack a address: %p\n", &stack_a);
	printf("stack b address: %p\n", &stack_b);

	// print the address stored in stack a and stack b
	printf("the initial address stored in stack a: %p\n", stack_a);
	printf("the initial address stored in stack b: %p\n", stack_b);
	
	// push some elements to the stack a 
	ft_new_node(&stack_a, 8);
	ft_new_node(&stack_a, 5);
	ft_new_node(&stack_a, 6);
	ft_new_node(&stack_a, 3);
	ft_new_node(&stack_a, 2);
	ft_new_node(&stack_a, 1);


	// Print the initial state of both stacks
	printf("Stack A: ");
	ft_print_stack(stack_a);
	printf("Stack B: ");
	ft_print_stack(stack_b);

	// perform the pb
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	ft_pb(&stack_a, &stack_b);
	
	
	// Print the new state of both stacks
	printf("Stack A: ");
	ft_print_stack(stack_a);
	printf("Stack B: ");
	ft_print_stack(stack_b);

	return (0);
}
