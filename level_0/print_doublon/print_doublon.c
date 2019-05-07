/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_doublon.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/08 09:04:41 by exam              #+#    #+#             */
/*   Updated: 2019/01/08 09:17:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdio.h>

void	print_doublon(int *a, int na, int *b, int nb)
{
	int		index_a;
	int		index_b;
	int		is_first;

	index_a = 0;
	index_b = 0;
	is_first = 0;
	while (index_a < na && index_b < nb)
	{
		if (a[index_a] == b[index_b])
		{
			if (is_first == 1)
				printf(" ");
			is_first = 1;
			printf("%d", a[index_a]);
			++index_a;
		}
		else if (a[index_a] > b[index_b])
			++index_b;
		else
			++index_a;

	}
	printf("\n");
}
