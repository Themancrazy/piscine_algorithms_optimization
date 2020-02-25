/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 19:05:12 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 19:10:24 by ghdesfos         ###   ########.fr       */
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
	char          *word;
	struct s_node *next;
};

/*--------------------------------
  :) function you must implement
  --------------------------------*/
void printReverse(struct s_node *lst);

/*--------------------------------
  ?? test function used in main 
  --------------------------------*/
struct s_node *createList(char **words, int n);

/*--------------------------------
  &  your own other function
  --------------------------------*/


#endif

