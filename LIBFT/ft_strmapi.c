/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 16:45:57 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/07 19:16:24 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	len;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (ft_strdup(""));
	len = ft_strlen(s);
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (new == NULL)
		return (NULL);
	while (i < len)
	{
		new[i] = (*f)(i, s[i]);
		++i;
	}
	new[i] = 0;
	return (new);
}

/*char map_func(unsigned int index, char c)
{
	if (c >= 'A' && c <= 'Z')
		return c + 32; 
	else
		return c; 
}
int main()
{
	char str1[] = "ABACATE";

	char *result = ft_strmapi(str1, &map_func);
	if (result != NULL)
	{
		printf("Resultado: %s\n", result);
		free(result); 
	}
	else
		printf("Erro ao processar a string.\n");

	return (0);
}*/