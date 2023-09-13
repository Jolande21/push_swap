/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:29:19 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 14:50:05 by jsteenpu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdlib.h>

typedef struct s_stack 
{
    int             value;
    struct s_stack  *next;
} t_stack;

t_stack	*ft_last_list(t_stack *a)
{
	t_stack *temp;

	temp = a;
	while (temp->next)
		temp = temp->next;
	return (temp);
}

// ra (rotate a): shift up all elements of stack a by 1
// the first element becomes the last one

void	ft_rb(t_stack **b)
{
	t_stack	*temp;
	t_stack	*last_node;
	
	if (!*b)
		return ;
	temp = *b;
	*b = (*b)->next;
	last_node = ft_last_list(*b);
	last_node->next = temp;
	temp->next = NULL;	
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
	printf("the address of the new node: %p\n", new);
	new->value = number;
	printf("the new value: %d\n", new->value);
	printf("the address stored in *stack assigned to new: %p\n", *stack);
	new->next = *stack;
	*stack = new;
	printf("the new address of *stack: %p\n", *stack);
}
int	main(void)
{
	t_stack *stack_b;

	stack_b = NULL;
	
	// print the address of stack b 
	printf("stack a address: %p\n", &stack_b);

	// print the address stored in stack a and stack b
	printf("the initial address stored in stack a: %p\n", stack_b);
	
	// push some elements to the stack a 
	ft_new_node(&stack_b, 10);
	ft_new_node(&stack_b, 9);
	ft_new_node(&stack_b, 8);
	ft_new_node(&stack_b, 7);


	// Print the initial state 
	printf("Stack B: ");
	ft_print_stack(stack_b);

	// perform the ra
	ft_rb(&stack_b);
	
	// Print the new state
	printf("Stack B: ");
	ft_print_stack(stack_b);

	return (0);
}