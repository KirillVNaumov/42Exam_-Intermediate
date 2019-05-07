/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_maxlenoc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/30 09:13:57 by exam              #+#    #+#             */
/*   Updated: 2019/04/30 09:48:18 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		++i;
	return i;
}

char	*ft_strdup(char *str)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 1));
	i = 0;
	while (str[i])
	{
		new[i] = str[i];
		++i;
	}
	new[i] = '\0';
	return (new);
}

char	*assign_new_template(char *str, int count_of_char, int index)
{
	char	*new;
	int		i;

	new = (char *)malloc(sizeof(char) * (count_of_char + 1));
	new[count_of_char] = '\0';
	i = 0;
	while (i < count_of_char)
	{
		new[i] = str[index];
		++i;
		++index;
	}
	return new;
}

int		find_string(char *str, char *template)
{
	int		i;
	int		j;

	i = 0;
	while (str[i])
	{
		j = 0;
		while (str[i + j] == template[j])
			++j;
		if (template[j] == '\0')
			return (1);
		++i;
	}
	return (0);
}

int		search(int argc, char **argv, char **final_string, int count_of_char)
{
	char	*template;
	int		i;
	int		j;

	i = 0;
	while (argv[1][i])
	{
		if (ft_strlen(argv[1]) - i < count_of_char)
			break ;
		template = assign_new_template(argv[1], count_of_char, i);
		j = 2;
		while (j < argc)
		{
			if (find_string(argv[j], template) == 0)
				break ;
			++j;
		}
		if (j == argc)
		{
			(*final_string) = ft_strdup(template);
			return (1);
		}
		++i;
	}
	return (0);
}

void	str_maxlenoc(int argc, char **argv)
{
	char 	*final_string;
	int		count_of_char;

	final_string = (char *)malloc(sizeof(char));
	final_string[0] = '\0';
	count_of_char = 1;
	while (search(argc, argv, &final_string, count_of_char) == 1)
		++count_of_char;
	write(1, final_string, ft_strlen(final_string));
}

int		main(int argc, char **argv)
{
	if (argc == 2)
		write(1, argv[1], ft_strlen(argv[1]));
	if (argc > 2)
		str_maxlenoc(argc, argv);
	write(1, "\n", 1);
}
