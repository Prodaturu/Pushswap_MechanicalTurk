/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sprodatu <sprodatu@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/27 05:23:09 by sprodatu          #+#    #+#             */
/*   Updated: 2024/02/25 01:16:11 by sprodatu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>
# include <stddef.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <string.h>

typedef struct node
{
	unsigned char	content;
	struct node		*next;
}					t_inode;

typedef struct s_queue
{
	struct node		*head;
	struct node		*tail;
	size_t			size;
}					t_iqueue;

char			*get_next_line(int fd);
int				new_line_check(char *str);
int				ft_enqueue(t_iqueue *q, unsigned char val);
unsigned char	ft_dequeue(t_iqueue *que);
char			*ft_get_line(t_iqueue *que);
void			ft_free_queue(t_iqueue *q);

#endif