/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kroselin <kroselin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 17:13:47 by kroselin          #+#    #+#             */
/*   Updated: 2019/10/14 12:42:16 by kroselin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	int		a;

	if (!s1 || !s2)
		return (0);
	i = ft_strlen(s1) + ft_strlen(s2);
	if (!(str = (char *)malloc((sizeof(str)) * (i + 1))))
		return (0);
	a = 0;
	while (*s1 != '\0')
	{
		str[a++] = *s1;
		s1++;
	}
	while (*s2 != '\0')
	{
		str[a++] = *s2;
		s2++;
	}
	str[a] = '\0';
	return (str);
}
