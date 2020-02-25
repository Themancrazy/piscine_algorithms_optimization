/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:46:54 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 21:58:32 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H

#include <stdio.h> //printf, scanf, ...
#include <string.h> //memcpy, strlen, ...
#include <unistd.h> //fork, write, sleep...
#include <stdlib.h> //malloc, free, exit...

/*--------------------------------
  !! required structure
  --------------------------------*/

struct s_node {
	char	*word;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/

//STACK

struct s_item {
  char          *word;
  struct s_item *next;
};

typedef struct s_item t_item;

struct s_stack {
	struct s_item *item;
};

typedef struct s_stack t_stack;

struct s_stack *stackInit(void);

void *pop(struct s_stack *stack);

void push(struct s_stack *stack, char *word);

//OTHER

void printReverseV2(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif
