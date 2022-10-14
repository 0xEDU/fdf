/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: etachott <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/11 15:15:34 by etachott          #+#    #+#             */
/*   Updated: 2022/10/04 18:40:38 by coder            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_digits(int n);
static void		fill_recursively(char *str, long int n);

char	*ft_itoa(int n)
{
	char		*str;
	size_t		i;
	long int	j;

	i = get_digits(n);
	str = malloc(sizeof(char) * i + 1);
	if (n < 0)
	{
		j = n;
		*str = '-';
		fill_recursively(str + i - 1, j * -1);
	}
	else
		fill_recursively(str + (i - 1), n);
	*(str + i) = '\0';
	return (str);
}

static void	fill_recursively(char *str, long int n)
{
	size_t	num;

	num = 0;
	if (n >= 10)
	{
		num = (n % 10) + '0';
		n = n / 10;
		fill_recursively(str - 1, n);
		*str = num;
	}
	else if (0 <= n && n <= 9)
	{
		n = n + '0';
		*str = n;
	}
}

static size_t	get_digits(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n != 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}
