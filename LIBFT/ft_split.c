/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 20:20:12 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/16 21:33:32 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wordcount(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static int	ft_wordlen(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static char	**ft_free(char **str, int i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**result;
	int		i;
	int		j;

	i = 0;
	j = 0;
	result = (char **)malloc((ft_wordcount(s, c) + 1) * sizeof(char *));
	if (!s || !result)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			result[j] = ft_substr(s, i, ft_wordlen(&s[i], c));
			if (!result[j])
				return (ft_free(result, j));
			j++;
			i += ft_wordlen(&s[i], c);
		}
		else
			i++;
	}
	result[j] = NULL;
	return (result);
}
/*int main(void)
{
    char **result;

    // Teste com uma string simples
    printf("Teste 1:\n");
    result = ft_split("Isabella neves", ' ');
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    // Teste com uma string contendo múltiplos espaços
    printf("\nTeste 2:\n");
    result = ft_split("   isabella   neves   ", ' ');
    if (result)
    {
        int i = 0;
        while (result[i] != NULL)
        {
            printf("%s\n", result[i]);
            free(result[i]);
            i++;
        }
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    // Teste com uma string vazia
    printf("\nTeste 3:\n");
    result = ft_split("", ' ');
    if (result)
    {
        printf("Aqui deveria estar vazio: %s\n", *result);
        free(result[0]);
        free(result);
    }
    else
    {
        printf("Erro: a função ft_split retornou NULL\n");
    }

    return 0;
    // cc ft_split.c ft_strlcpy.c ft_strlen.c ft_strchr.c ft_substr.c ft_strdup.c
}*/
