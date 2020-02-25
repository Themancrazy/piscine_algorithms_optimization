/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:02:17 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 23:36:37 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_queue	*queueInit(void)
{
	t_queue *queue;

	if (!(queue = (t_queue*)malloc(sizeof(t_queue))))
		return (NULL);
	queue->first = NULL;
	queue->last = NULL;
	return (queue);
}

char			*dequeue(struct s_queue *queue)
{
	t_node	*tmp;
	char	*str;

	if (!queue)
		return (NULL);
	else if (queue->first == NULL)
		return (NULL);
	else if (queue->first == queue->last)
	{
		tmp = queue->first;
		str = tmp->message;
		queue->first = NULL;
		queue->last = NULL;
		free(tmp);
		return (str);
	}
	else
	{
		tmp = queue->first;
		str = tmp->message;
		queue->first = tmp->next;
		free(tmp);
		return (str);
	}
}

void			enqueue(struct s_queue *queue, char *message)
{
	t_node	*new;
	t_node	*tmp;

	if (!queue || !message)
		return ;
	if (!(new = (t_node*)malloc(sizeof(t_node))))
		return ;
	new->message = message;
	if (queue->first == NULL)
	{
		queue->first = new;
		queue->last = new;
	}
	else
	{
		tmp = queue->last;
		tmp->next = new;
		queue->last = new;
	}
}

char			*peek(struct s_queue *queue)
{
	if (!queue)
		return (NULL);
	if (queue->first == NULL)
		return (NULL);
	return (queue->first->message);
}

int				isEmpty(struct s_queue *queue)
{
	if (queue->first == NULL)
		return (1);
	return (0);
}
