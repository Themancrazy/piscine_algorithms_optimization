/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverseV2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:46:30 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 21:14:01 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack	*stackInit(void)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->item = NULL;
	return (stack);
}

void	*pop(struct s_stack *stack)
{
	t_item	*item;
	char	*word;

	if (!stack)
		return (NULL);
	if (!(stack->item))
		return (NULL);
	item = stack->item;
	word = stack->item->word;
	stack->item = stack->item->next;
	free(item);
	return ((void*)word);
}

void	push(struct s_stack *stack, char *word)
{
	t_item *item;

	if (!stack || !word)
		return ;
	if (!(item = (t_item*)malloc(sizeof(item))))
		return ;
	item->word = word;
	item->next = stack->item;
	stack->item = item;
}

void	printReverseV2(struct s_node *lst)
{
	t_stack	*stack;

	stack = stackInit();
	while (lst)
	{
		push(stack, lst->word);
		lst = lst->next;
	}
	while (stack->item)
	{
		printf("%s", stack->item->word);
		pop(stack);
		if (stack->item)
			printf(" ");
	}
}
