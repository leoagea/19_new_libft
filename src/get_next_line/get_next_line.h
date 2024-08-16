/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 12:15:49 by vdarras           #+#    #+#             */
/*   Updated: 2024/08/16 18:46:28 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
	ssize_t			len;
}					t_list;

t_list				*lstnew(char *content);
void				lstadd_back(t_list **lst, t_list *new);
char				*ft_strchr_bis(t_list *lst, int c, int loop);
char				*strdup(const char *s1);
void				ft_strjoin_bis(char *line, t_list *node, size_t len);
t_list				**free_node(t_list **node, int loop);
char				*get_line_from_list(t_list *lst);
void				clean_buffer(t_list **lst);
int					read_to_buffer(int fd, t_list **lst);
char				*get_next_line(int fd);

#endif