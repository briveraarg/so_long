/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brivera <brivera@student.42madrid.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/27 16:15:39 by brivera           #+#    #+#             */
/*   Updated: 2024/09/28 11:36:49 by brivera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*ps;
	size_t	i;
	size_t	len;

	len = ft_strlen(str);
	ps = malloc(len + 1);
	if (ps == NULL)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		ps[i] = str[i];
		i++;
	}
	ps[i] = '\0';
	return (ps);
}
