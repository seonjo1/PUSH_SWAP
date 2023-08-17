/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonjo <seonjo@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/01 18:02:49 by seonjo            #+#    #+#             */
/*   Updated: 2023/08/17 18:10:09 by seonjo           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	*all_free(t_glist **head)
{
	t_glist	*node;
	t_glist	*tmp;

	node = *head;
	while (node != NULL)
	{
		tmp = node -> next;
		free(node);
		node = tmp;
	}
	return (NULL);
}

void	*remove_node(t_glist **head, int fd)
{
	t_glist	*pre;
	t_glist	*now;

	now = *head;
	if (now -> fd == fd)
	{
		*head = now -> next;
		free(now);
		return (NULL);
	}
	while (now -> fd != fd)
	{
		pre = now;
		now = pre -> next;
	}
	pre -> next = now -> next;
	free(now);
	return (NULL);
}

void	*free_dest(char *dest)
{
	free(dest);
	return (NULL);
}

t_glist	*find_node(t_glist **head, int fd)
{
	t_glist	*node;
	t_glist	*pre_node;

	node = *head;
	pre_node = NULL;
	while (node != NULL && node -> fd != fd)
	{
		pre_node = node;
		node = pre_node -> next;
	}
	if (node == NULL)
	{
		node = (t_glist *)malloc(sizeof(t_glist));
		if (node == NULL)
			return (NULL);
		node -> fd = fd;
		(node -> buffer)[0] = '\0';
		node -> next = NULL;
		if (pre_node == NULL)
			*head = node;
		else
			pre_node -> next = node;
	}
	return (node);
}
