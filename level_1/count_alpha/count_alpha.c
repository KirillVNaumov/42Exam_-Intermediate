/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_alpha.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:05:54 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 09:12:29 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int		count_letters(char *str, char c)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == c)
			++count;
		++i;
	}
	return (count);
}

void	count_alpha(char *str)
{
	int		i;
	int		is_first;
	int		alpha[128];

	i = 0;
	while (i < 128)
		alpha[i++] = 0;
	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + 32;
		++i;
	}
	i = 0;
	is_first = 1;
	while (str[i])
	{
		if (str[i] >= 'a' && str[i] <= 'z' && alpha[(int)str[i]] == 0)
		{
			alpha[(int)str[i]] = 1;
			if (!is_first)
				printf(", ");
			is_first = 0;
			printf("%d%c", count_letters(str, str[i]), str[i]);
		}
		++i;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		count_alpha(argv[1]);
	printf("\n");
}
