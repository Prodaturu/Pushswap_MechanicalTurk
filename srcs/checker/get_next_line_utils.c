/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 07:01:13 by sprodatu          #+#    #+#             */
/*   Updated: 2023/10/28 06:49:34 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	new_line_check(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

int	ft_enqueue(t_iqueue *q, unsigned char val)
{
	t_inode	*newnode;

	if (!q)
		return (0);
	newnode = malloc(sizeof(t_inode));
	if (!newnode)
		return (0);
	newnode->content = val;
	newnode->next = NULL;
	if (q->tail)
		q->tail->next = newnode;
	q->tail = newnode;
	if (!q->head)
		q->head = newnode;
	q->size = q->size + 1;
	return (1);
}

unsigned char	ft_dequeue(t_iqueue *que)
{
	unsigned char	removed;
	t_inode			*temp;

	if (que->head == NULL)
	{
		que->tail = NULL;
		return (0);
	}
	temp = que->head;
	removed = temp->content;
	que->head = que->head->next;
	que->size -= 1;
	if (que->head == NULL)
		que->tail = NULL;
	free(temp);
	temp = NULL;
	return (removed);
}

char	*ft_get_line(t_iqueue *que)
{
	char			*line;
	int				length;
	int				index;
	unsigned char	c;

	index = 0;
	length = que->size +1;
	line = malloc(sizeof(char) * length);
	if (!line)
		return (NULL);
	while (index < length -1)
	{
		c = ft_dequeue(que);
		if (c != '\n')
			line[index++] = c;
		else
		{
			line[index++] = c;
			line[index] = '\0';
			return (line);
		}
	}
	line[index] = '\0';
	return (line);
}
