/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precious.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 17:36:34 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 19:04:07 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

t_node	*add_new_element_to_list(t_node *cur, char c)
{
	t_node *new;

	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return (NULL);
	cur->next = new;
	new->c = c;
	new->prev = cur;
	new->next = NULL;
	return (new);
}

void	create_double_link_list(t_node **head)
{
	t_node	*cur;
	int		i;

	if (!(*head = (t_node*)malloc(sizeof(t_node))))
		return ;
	(*head)->c = CS[0];
	(*head)->prev = NULL;
	(*head)->next = NULL;
	cur = *head;
	i = 1;
	while (CS[i])
	{
		cur = add_new_element_to_list(cur, CS[i]);
		i++;
	}
	cur->next = *head;
	(*head)->prev = cur;
}

char	*get_text(int *text, int size, t_node *tmp)
{
	char	*str;
	int		i;
	int		j;

	if (!(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = -1;
	while (++i < size)
	{
		j = 0;
		if (text[i] >= 0)
		{
			while (j++ < text[i])
				tmp = tmp->next;
			str[i] = tmp->c;
		}
		else
		{
			while (j-- > text[i])
				tmp = tmp->prev;
			str[i] = tmp->c;
		}
	}
	str[size] = 0;
	return (str);
}

char	*precious(int *text, int size)
{
	t_node	*head;
	char	*str;

	create_double_link_list(&head);
	str = get_text(text, size, head);
	return (str);
}
