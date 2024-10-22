/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:49:11 by isneves-          #+#    #+#             */
/*   Updated: 2024/04/28 15:15:59 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}

/*int main()
{
    int c = 'A';
    int result = ft_tolower(c);

    printf("Caractere original: %c\n", c);
    printf("Caractere convertido: %c\n", result);

    return 0; 
}*/
