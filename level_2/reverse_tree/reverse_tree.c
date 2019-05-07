/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/02 09:27:09 by exam              #+#    #+#             */
/*   Updated: 2019/04/02 09:29:51 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

struct s_node {
	int           value;
	struct s_node *right;
	struct s_node *left;
};

void		reverse_tree(struct s_node *root)
{
	struct s_node	*tmp;

	if (!root)
		return ;
	if (root->left)
		reverse_tree(root->left);
	if (root->right)
		reverse_tree(root->right);

	tmp = root->left;
	root->left = root->right;
	root->right = tmp;
}
