/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_pivot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 09:14:48 by exam              #+#    #+#             */
/*   Updated: 2019/04/16 09:20:47 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	find_pivot(int *arr, int n)
{
	int		sum_left;
	int		sum_right;
	int		i;

	sum_left = 0;
	sum_right = 0;
	i = 1;
	while (i < n)
		sum_right += arr[i++];
	i = 0;
	while (i < n)
	{
		if (sum_left == sum_right)
			return (i);
		sum_left += arr[i];
		if (i != n)
			sum_right -= arr[i + 1];
		++i;
	}
	return (-1);
}
