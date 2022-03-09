/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft - ft_isspace.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/04 18:02:37 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/05 07:00:40 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_isspace(int c)
{
	return ((unsigned)c == ' ' || (((unsigned)c - '\t') < 5));
}