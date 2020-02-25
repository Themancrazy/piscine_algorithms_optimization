/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 23:09:47 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 23:36:34 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int main(void)
{

	/*-------------------
	launch your test here
	--------------------*/

	struct s_queue *q = queueInit();
	printf("is empty = %d\n", isEmpty(q));
	enqueue(q, "Hello");
	enqueue(q, "How");
	enqueue(q, "Are");
	enqueue(q, "You");
	enqueue(q, "?");
	printf("is empty = %d\n", isEmpty(q));
	for (int i = 0; i < 5; i++)
	{
		printf("%s\n", peek(q));
		printf("%s\n", dequeue(q));
	}
		printf("is empty = %d\n", isEmpty(q));
	return (0);
}



// Function used for the test
// Don't go further :)


