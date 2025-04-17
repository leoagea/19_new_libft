/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lagea < lagea@student.s19.be >             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:23:29 by lagea             #+#    #+#             */
/*   Updated: 2025/04/17 16:28:04 by lagea            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

char	*ft_join_path(char *path, char *cmd)
{
	char	*tmp;
	char	*res;

	if (!cmd)
		return (NULL);
	if (!path)
		return (ft_strdup(cmd));
	tmp = ft_strjoin(path, "/");
	if (!tmp)
		return (NULL);
	res = ft_strjoin(tmp, cmd);
	free(tmp);
	return (res);
}