/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   height_tree.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:30:43 by exam              #+#    #+#             */
/*   Updated: 2019/03/26 09:35:49 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node **nodes;
};

void		find_height(struct s_node *root, int curr_depth, int *height)
{
	int		i;

	if (curr_depth > *height)
		*height = curr_depth;
	if (!root || !root->nodes || !root->nodes[0])
		return ;
	i = 0;
	while (root->nodes[i])
	{
		find_height(root->nodes[i], curr_depth + 1, height);
		++i;
	}
}

int height_tree(struct s_node *root)
{
	int		height;

	if (!root)
		return (-1);
	if (!root->nodes || !root->nodes[0])
		return (0);

	height = 0;

	find_height(root, 0, &height);
	return (height);
}
