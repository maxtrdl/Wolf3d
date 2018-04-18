/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtrudel <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/12 12:58:00 by mtrudel           #+#    #+#             */
/*   Updated: 2016/11/15 17:27:16 by mtrudel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*dest;
	int		start_s;
	int		end_s;
	int		i;

	i = 0;
	start_s = 0;
	if (s == NULL)
		return (NULL);
	end_s = ft_strlen(s) - 1;
	while (s[start_s] == ' ' || s[start_s] == '\n' || s[start_s] == '\t')
		start_s++;
	while ((s[end_s] == ' ' || s[end_s] == '\n' || s[end_s] == '\t') \
			&& (end_s > start_s))
		end_s--;
	dest = (char*)malloc(((ft_strlen(s) - \
					((ft_strlen(s) - end_s) + start_s)) + 2) * sizeof(char));
	if (dest == NULL)
		return (NULL);
	while (start_s <= end_s)
		dest[i++] = s[start_s++];
	dest[i] = '\0';
	return (dest);
}
