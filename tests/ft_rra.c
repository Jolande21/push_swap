/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsteenpu <jsteenpu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/13 15:06:15 by jsteenpu          #+#    #+#             */
/*   Updated: 2023/09/13 16:24:28 by jsteenpu         ###   ########.fr       */
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
void	ft_rra(t_stack **a)
{
	t_stack	*tmp;
	int		i;

	if (!*a || !(*a)->next)
		return ;
	i = 0;
	tmp = *a; // 5850
	printf("the address stored in temp (= *a) before: %p\n", tmp); // 5850
	printf("the address stored in (*a)->next before: %p\n", (*a)->next); // 5840
	while ((*a)->next)
	{
		*a = (*a)->next;
		printf("the new address stored in (*a): %p\n", *a); // 5850
		i++;
	}
	printf("the number of nodes i: %d\n", i);
	(*a)->next = tmp; // 5840 -> 5850; the last node points to the 'old' first node
	printf("the address stored in temp (= *a) before: %p\n", tmp); // 5850
	printf("the address stored in (*a)->next after: %p\n", (*a)->next);
	while (i > 1)
	{
		tmp = tmp->next;
		printf("the address stored in temp after: %p\n", tmp);
		i--;
	}
	tmp->next = NULL;
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
	ft_rra(&stack_a);
	
	// Print the new state
	printf("Stack A: ");
	ft_print_stack(stack_a);

	return (0);
}