/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_of_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 09:01:40 by exam              #+#    #+#             */
/*   Updated: 2019/02/19 09:06:44 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			find_twos(int i)
{
	int		count;

	count = 0;
	while (i > 9)
	{
		if (i % 10 == 2)
			++count;
		i = i / 10;
	}
	if (i == 2)
		++count;
	return (count);
}

int			count_of_2(int n)
{
	int		i;
	int		count;

	i = 2;
	count = 0;
	while (i <= n)
	{
		count += find_twos(i);
		++i;
	}
	return (count);
}
