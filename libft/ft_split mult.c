/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvargas <fvargas@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/17 18:48:41 by fvargas           #+#    #+#             */
/*   Updated: 2024/07/18 19:15:17 by fvargas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



static size_t	count_words(char const *s, char *c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (ft_strchr(c, s[i]) == 0)
		{
			count++;
			while (s[i] && ft_strchr(c, s[i]) == 0)
				i++;
		}
		else if (ft_strchr(c, s[i]))
			i++;
	}
	return (count);
}

static void	free_memory(size_t item_count, char **dest)
{
	while (item_count > 0)
	{
		item_count--;
		free(*(dest + item_count));
	}
	free(dest);
}

static char	*get_word(char const *s, char *c)
{
	size_t	i;
	char	*word;

	i = 0;
	while (s[i] && ft_strchr(c, s[i]) == 0)
		i++;
	word = (char *)malloc(sizeof(char) * (i + 1));
	if (!word)
		return (0);
	word[i] = '\0';
	i--;
	while (i > 0)
	{
		word[i] = s[i];
		i--;
	}
	word[i] = s[i];
	return (word);
}

static char	**split(char const *s, char *c, char **a, size_t n)
{
	size_t	j;
	size_t	i;

	i = 0;
	j = 0;
	while (i < n)
	{
		while (s[j] && ft_strchr(c, s[i]))
			j++;
		a[i] = get_word(&s[j], c);
		if (!a[i])
		{
			free_memory(i, a);
			return (0);
		}
		while (s[j] && ft_strchr(c, s[i]) == 0)
			j++;
		i++;
	}
	a[i] = NULL;
	return (a);
}

char	**ft_split_mult(const char *s, char *charset, int *words)
{
	char	**array;

	if (!s)
		return (0);
	
	*words = count_words(s, charset);
	array = malloc((*words + 1) * sizeof(char *));
	if (!array)
		return (0);
	array = split(s, charset, array, *words);
	return (array);
}
