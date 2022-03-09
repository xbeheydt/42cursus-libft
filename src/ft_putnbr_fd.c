/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xbeheydt <xbeheydt@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/17 08:44:48 by xbeheydt          #+#    #+#             */
/*   Updated: 2021/11/17 09:09:13 by xbeheydt         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_putnbr_fd(int n, int fd)
{
	if (fd >= 0)
	{
		if (n < 0)
			ft_putchar_fd('-', fd);
		if (n <= -10 || 10 <= n)
		{
			if (n < 0)
				ft_putnbr_fd(-(n / 10), fd);
			else
				ft_putnbr_fd((n / 10), fd);
		}
		if (n > 0)
			ft_putchar_fd('0' + (n % 10), fd);
		else
			ft_putchar_fd('0' + -(n % 10), fd);
	}
}
