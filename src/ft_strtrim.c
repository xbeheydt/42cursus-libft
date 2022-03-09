/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 15:38:26 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 09:40:48 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	ft_chrcmp(char c, char const *set)
{
	while (*set)
		if (c == *set++)
			return (1);
	return (0);
}

static int	ft_findpos(char const *str, char const *set, int pos)
{
	int	ret;

	ret = pos;
	while (str[ret])
	{
		if (pos == 0 && !ft_chrcmp(str[ret], set))
			break ;
		if (pos > 0 && ft_chrcmp(str[ret], set))
			break ;
		++ret;
	}
	return (ret);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	start = ft_findpos(s1, set, 0);
	if (s1_len == 0)
		return (ft_substr(s1, 0, 0));
	if (ft_strlen(set) == 0)
		return (ft_substr(s1, 0, s1_len));
	end = ft_findpos(s1, set, start + 1);
	return (ft_substr(s1, start, end - start));
}
