/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   console.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ghdesfos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:20:41 by ghdesfos          #+#    #+#             */
/*   Updated: 2019/06/13 22:58:58 by ghdesfos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

struct s_stack	*initStack(void)
{
	t_stack *stack;

	if (!(stack = (t_stack*)malloc(sizeof(t_stack))))
		return (NULL);
	stack->item = NULL;
	return (stack);
}

void			push(struct s_stack *stack, int idx)
{
	t_item *item;

	if (!stack)
		return ;
	if (!(item = (t_item*)malloc(sizeof(item))))
		return ;
	item->idx = idx;
	item->next = stack->item;
	stack->item = item;
}

int				pop(struct s_stack *stack)
{
	t_item	*item;
	int		idx;

	if (!stack)
		return (-1);
	if (!(stack->item))
		return (-1);
	item = stack->item;
	idx = stack->item->idx;
	stack->item = stack->item->next;
	free(item);
	return (idx);
}

char	*concat_strings_basic(char *s1, char *s2)
{
	char	*new;
	int		l1;
	int		l2;
	int		i1;
	int		i2;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (strdup((s1) ? s1 : s2));
	l1 = strlen(s1);
	l2 = strlen(s2);
	new = NULL;
	if (!(new = (char*)malloc(sizeof(char) * (l1 + l2 + 1))))
		return (NULL);
	i1 = -1;
	while (++i1 < l1)
		new[i1] = s1[i1];
	i2 = -1;
	while (++i2 < l2)
		new[i1 + i2] = s2[i2];
	new[l1 + l2] = 0;
	return (new);
}

char	*concat_strings_with_separator(char *s1, char *s2, char *separator)
{
	char *new;
	char *tmp;

	if (!s1 && !s2)
		return (NULL);
	if (!s1 || !s2)
		return (strdup((s1) ? s1 : s2));
	tmp = concat_strings_basic(s1, separator);
	new = concat_strings_basic(tmp, s2);
	free(tmp);
	return (new);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	while (*str)
	{
		write (1, str, 1);
		str++;
	}
}

char	*console(void)
{
	t_stack	*stack;
	char	*buf;
	char	*str;
	char	*tmp;
	size_t	len;
	size_t	ret;

	stack = initStack();
	len = 256;
	if (!(buf = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	str = NULL;
	while (1)
	{
		ft_putstr("?: ");
		ret = getline(&buf, &len, stdin);
		if (ret > 0)
			buf[ret - 1] = 0;
		if (ret > 255)
			buf[255] = 0;
		if (strcmp(buf, "SEND") == 0)
		{
			return (str);
		}
		else if (strcmp(buf, "UNDO") == 0)
			str[strlen(str) - pop(stack)] = 0;	
		else if (buf && *buf)
		{
			push(stack, ret);
			tmp = str;
			str = concat_strings_with_separator(str, buf, " ");
			free(tmp);
		}
		printf("%s\n", str);
	}
	return (NULL);
}
