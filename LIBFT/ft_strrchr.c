/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:39:46 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/13 21:34:22 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*last;

	last = NULL;
	while (*s != '\0')
	{
		if (*s == (char)c)
		{
			last = s;
		}
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return ((char *)last);
}
/*
int main() 
{
    const char *str = "One piece";
    int c = 'e'; 
    char *result = ft_strrchr(str, c);
	
    if (result != NULL) 
        printf("Última ocorrência encontrada: %s\n", result);
	else 
        printf("Caractere '%c' não encontrado na string.\n", c);
    return 0;
}*/
