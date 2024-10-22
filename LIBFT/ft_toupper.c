/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: isneves- <isneves-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/28 12:50:54 by isneves-          #+#    #+#             */
/*   Updated: 2024/04/28 15:15:19 by isneves-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

/*int main()
{
    int c = 'a'; 
    int result = ft_toupper(c);

    printf("Caractere original: %c\n", c);
    printf("Caractere convertido: %c\n", result);

    return 0; 
}*/
