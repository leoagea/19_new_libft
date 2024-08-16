/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea <lagea@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 23:46:57 by lagea             #+#    #+#             */
/*   Updated: 2024/08/16 12:52:50 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	index;
	char	*new_s;

	index = 0;
	if (!s)
		return (NULL);
	len = ft_strlen(s);
	new_s = (char *)malloc((len + 1) * sizeof(char));
	if (!new_s)
		return (NULL);
	while (s[index])
	{
		new_s[index] = (*f)(index, s[index]);
		index++;
	}
	new_s[index] = '\0';
	return (new_s);
}
