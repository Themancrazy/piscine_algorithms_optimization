/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:06:16 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 19:41:22 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	printReverse(struct s_node *lst)
{
	if (!lst)
		return ;
	printReverse(lst->next);
	if (lst->next)
		printf(" ");
	printf("%s", lst->word);
}
