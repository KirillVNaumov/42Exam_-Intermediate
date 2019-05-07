/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:10:26 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 09:25:37 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

struct s_node {
	void          *content;
	struct s_node *next;
};

struct s_stack {
	struct s_node *top;
};

struct s_stack *init(void)
{
	struct s_stack		*stack;

	stack = (struct s_stack *)malloc(sizeof(struct s_stack));
	stack->top = NULL;
	return (stack);
}

void *pop(struct s_stack *stack)
{
	void		*content;

	if (!stack || !stack->top)
		return (NULL);
	content = stack->top->content;
	stack->top = stack->top->next;
	return (content);
}

void push(struct s_stack *stack, void *content)
{
	struct s_node		*new;

	new = (struct s_node *)malloc(sizeof(struct s_node));
	new->content = content;

	if (!stack)
		return ;
	if (!stack->top)
	{
		stack->top = new;
		new->next = NULL;
		return ;
	}
	new->next = stack->top;
	stack->top = new;
}

void *peek(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (NULL);
	return (stack->top->content);
}

int isEmpty(struct s_stack *stack)
{
	if (!stack || !stack->top)
		return (1);
	return (0);
}

/*#include <stdio.h>

int		main()
{
	struct s_stack		*stack;
	void				*node;

	stack = NULL;
	
	printf("isEmpty = %d\n", isEmpty(stack));
	
	printf("init\n");
	stack = init();

	printf("push (1)\n");
	push(stack, "1");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));


	printf("push (2)\n");
	push(stack, "2");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));

	printf("push (3)\n");
	push(stack, "3");
	printf("isEmpty = %d peek = %s\n", isEmpty(stack), (char *)peek(stack));


	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);

	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);


	printf("pop\n");
	node = pop(stack);
	printf("isEmpty = %d peek = %s pop = %s\n", isEmpty(stack), (char *)peek(stack), (char *)node);
}
*/
