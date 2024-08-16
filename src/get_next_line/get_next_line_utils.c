/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/22 22:29:25 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 12:52:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

int	my_strlen(const char *str)
{
	int	len;

	len = 0;
	if (!str)
		return (0);
	while (*str++)
	{
		len++;
	}
	return (len);
}

char	*strchr_index(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return ((char *)&str[i]);
		i++;
	}
	if (str[i] == '\n')
		return ((char *)&str[i]);
	return (NULL);
}

char	*strjoin(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*res;

	res = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!res)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		res[i++] = s1[j++];
	j = 0;
	while (s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	return (res);
}

char	*my_strdup(char *s1)
{
	char			*dest;
	unsigned int	i;

	if (!s1)
		return (NULL);
	dest = (char *)malloc(ft_strlen(s1) + 1);
	if (!dest)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*substr(char *s, int start, int len)
{
	int		i;
	int		len_s;
	char	*str;

	if (!s)
		return (NULL);
	if (start > my_strlen(s))
		return (malloc(1));
	len_s = my_strlen(s + start);
	if (len > len_s)
		len = len_s;
	str = malloc((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = s[start + i];
		i++;
	}
	str[i] = 0;
	return (str);
}
