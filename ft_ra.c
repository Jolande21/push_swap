/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 14:29:19 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 14:45:07 by jsteenpu         ###   ########.fr       */
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

void	ft_ra(t_stack **a)
{
	t_stack	*last_node;
	t_stack *temp;
	
	if (!*a)
		return ;
	printf("the address stored in *a: %p\n", *a);
	printf("the address of (*a)->next: %p\n", (*a)->next);
	temp = *a; // 0x5850
	*a = (*a)->next; // 0x5840
	printf("the new address stored in *a: %p\n", *a);
	printf("the address of (*a)->next: %p\n", (*a)->next);
	last_node = ft_last_list(*a); // 0x5820
	printf("the address of the last node: %p\n", last_node);
	printf("the address of the (last node)->next: %p\n", last_node->next);
	last_node->next = temp; // 0x5840
	printf("the new address of the (last node)->next: %p\n", last_node->next);
	printf("the new address of the (last node)->next: %p\n", last_node->next->next);
	temp->next = NULL;
	printf("the new address of the (last node)->next: %p\n", last_node->next->next);
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
	t_stack *stack_a;

	stack_a = NULL;
	
	// print the address of stack a 
	printf("stack a address: %p\n", &stack_a);

	// print the address stored in stack a and stack b
	printf("the initial address stored in stack a: %p\n", stack_a);
	
	// push some elements to the stack a 
	ft_new_node(&stack_a, 10);
	ft_new_node(&stack_a, 9);
	ft_new_node(&stack_a, 8);
	ft_new_node(&stack_a, 7);


	// Print the initial state 
	printf("Stack A: ");
	ft_print_stack(stack_a);

	// perform the ra
	ft_ra(&stack_a);
	
	// Print the new state
	printf("Stack A: ");
	ft_print_stack(stack_a);

	return (0);
}