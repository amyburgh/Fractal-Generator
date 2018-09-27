/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amyburgh <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 15:51:06 by amyburgh          #+#    #+#             */
/*   Updated: 2018/06/21 20:12:07 by amyburgh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "get_next_line.h"
#include "libft.h"

static t_list	*add_link(t_list **list, int fd)
{
	t_list	*temp;

	temp = ft_lstnew("\0", fd);
	temp->content_size = (size_t)fd;
	if (!(*list))
	{
		temp->next = temp;
		return (temp);
	}
	temp->next = (*list)->next;
	(*list)->next = temp;
	return (temp);
}

static t_list	*find_fd(t_list **list, int fd)
{
	int		index;

	if (!(*list))
		return (add_link(list, fd));
	if ((int)(*list)->content_size == fd)
		return (*list);
	index = (int)(*list)->content_size;
	(*list) = (*list)->next;
	while ((int)(*list)->content_size != index)
	{
		if ((int)(*list)->content_size == fd)
			return (*list);
		*list = (*list)->next;
	}
	return (add_link(list, fd));
}

static void		store_overflow(t_list *list)
{
	char	*temp;

	if ((temp = ft_strchr(list->content, '\n')))
	{
		temp = ft_strdup(temp + 1);
		free(list->content);
		list->content = temp;
	}
	else
		ft_strclr(list->content);
}

int				get_next_line(const int fd, char **line)
{
	char			buf[BUFF_SIZE + 1];
	char			*temp;
	static t_list	*list;
	size_t			bytes;

	if (fd < 0 || !line || BUFF_SIZE < 1 || read(fd, buf, 0) < 0)
		return (-1);
	list = find_fd(&list, fd);
	while ((bytes = read(fd, buf, BUFF_SIZE)))
	{
		buf[bytes] = '\0';
		if (!(temp = ft_strjoin(list->content, buf)))
			return (-1);
		free(list->content);
		list->content = temp;
		if (ft_strchr(list->content, '\n'))
			break ;
	}
	if (!bytes && !ft_strlen(list->content))
		return (0);
	if (!(*line = ft_strnew(ft_strlen(list->content))))
		return (-1);
	*line = ft_strccpy(*line, list->content, '\n');
	store_overflow(list);
	return (1);
}
