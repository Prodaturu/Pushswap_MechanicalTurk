/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:23:18 by sprodatu          #+#    #+#             */
/*   Updated: 2023/11/19 23:28:01 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t			length;
	unsigned char	*start;

	length = 0;
	start = (unsigned char *) b;
	while (length < len)
	{
		*start = (unsigned char) c;
		length++;
		start++;
	}
	return (b);
}

void	clear_queue(t_iqueue *q)
{
	t_inode	*tmp;

	while (q->head)
	{
		tmp = q->head;
		q->head = q->head->next;
		free(tmp);
	}
	q->tail = NULL;
	q->size = 0;
}

char	*get_next_line(int fd)
{
	int				index;
	int				count;
	char			buff[BUFFER_SIZE + 1];
	char			*line;
	static t_iqueue	q;

	while (1)
	{
		count = read(fd, buff, BUFFER_SIZE);
		if (count < 0)
		{
			clear_queue(&q);
			return (NULL);
		}
		buff[count] = '\0';
		index = 0;
		while (count > 0 && buff[index])
			ft_enqueue(&q, buff[index++]);
		if (new_line_check(buff) || count == 0)
			break ;
	}
	if (q.size == 0)
		return (NULL);
	line = ft_get_line(&q);
	return (line);
}

// int main()
// {
// 	char *line;

// 	int fd = open("test.txt", O_RDONLY);
// 	line = get_next_line(fd);
// 	int i = 0;
// 	while (i++ < 10)
// 	{
// 		printf("%s\n", line);
// 		line = get_next_line(fd);
// 	}
// 	return (0);
// }
