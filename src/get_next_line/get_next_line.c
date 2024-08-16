/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:47 by vdarras           #+#    #+#             */
/*   Updated: 2024/08/16 18:45:37 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_list	**free_node(t_list **node, int loop)
{
	t_list	*tmp;

	if (!node || !*node)
		return (NULL);
	while (*node)
	{
		tmp = (*node)->next;
		free((*node)->content);
		free(*node);
		*node = tmp;
		if (!loop)
			break ;
	}
	return (node);
}

char	*get_line_from_list(t_list *lst)
{
	t_list	*head;
	char	*line;
	size_t	len;
	size_t	total_len;

	head = lst;
	len = 0;
	total_len = 0;
	while (lst && !ft_strchr_bis(lst, '\n', 0))
	{
		len += lst->len;
		lst = lst->next;
	}
	if (lst)
		len += (ft_strchr_bis(lst, '\n', 0) - lst->content) + 1;
	line = (char *)malloc(sizeof(char) * (len + 1));
	if (!line)
		return (NULL);
	lst = head;
	ft_strjoin_bis(line, head, len);
	line[len] = '\0';
	return (line);
}

void	clean_buffer(t_list **lst)
{
	t_list	*curr;
	t_list	*next;
	char	*newline_pos;

	curr = *lst;
	while (curr && !ft_strchr_bis(curr, '\n', 0))
		curr = *(free_node(lst, 0));
	if (curr)
	{
		newline_pos = ft_strchr_bis(curr, '\n', 0);
		if (newline_pos)
		{
			next = lstnew(strdup(newline_pos + 1));
			if (next)
			{
				next->next = curr->next;
				free_node(&curr, 0);
				*lst = next;
			}
		}
		else
		{
			lst = free_node(&curr, 1);
		}
	}
}

int	read_to_buffer(int fd, t_list **lst)
{
	char	*buf;
	ssize_t	bytes_read;
	t_list	*new_node;

	buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (-1);
	bytes_read = read(fd, buf, BUFFER_SIZE);
	if (bytes_read <= 0)
	{
		free(buf);
		return (bytes_read);
	}
	buf[bytes_read] = '\0';
	new_node = lstnew(buf);
	if (!new_node)
	{
		free(buf);
		return (-1);
	}
	lstadd_back(lst, new_node);
	return (bytes_read);
}

char	*get_next_line(int fd)
{
	static t_list	*bf;
	char			*line;
	int				res;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	res = 1;
	while ((bf == NULL || ft_strchr_bis(bf, '\n', 1) == NULL) && res > 0)
	{
		res = read_to_buffer(fd, &bf);
		if (res < 0)
		{
			free_node(&bf, 1);
			return (NULL);
		}
	}
	line = get_line_from_list(bf);
	if (line == NULL || *line == '\0')
	{
		free_node(&bf, 1);
		free(line);
		return (NULL);
	}
	clean_buffer(&bf);
	return (line);
}