/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 12:35:31 by isneves-          #+#    #+#             */
/*   Updated: 2024/05/13 21:29:58 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	while (*str != '\0' && *str != (char)c)
		str++;
	if (*str == (char)c)
	{
		return ((char *)str);
	}
	else
		return (NULL);
}
/*
int main() 
{
    const char *str = "One piece";
    int c = 'p'; 
    char *result = strchr(str, c);

    if (result != NULL) 
        printf("Encontrou: %s\n", result);
    else 
        printf("Caractere '%c' não encontrado na string.\n", c);
    return 0;
}*/
