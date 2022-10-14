/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: coder <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 19:54:52 by coder             #+#    #+#             */
/*   Updated: 2022/08/30 20:39:02 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	neg_counter;
	int	final_num;

	neg_counter = 0;
	final_num = 0;
	while (*str == ' ' || *str == '\t' || *str == '\r'
		|| *str == '\n' || *str == '\f' || *str == '\v')
		str++;
	if (*str == 43 || *str == 45)
	{
		if (*str == 45)
			neg_counter = 1;
		str++;
	}
	while (48 <= *str && *str <= 57)
	{
		final_num = (*str - 48) + (final_num * 10);
		str++;
	}
	if (neg_counter == 1)
		return (final_num * -1);
	else
		return (final_num);
}
