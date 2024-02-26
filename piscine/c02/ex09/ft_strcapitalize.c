/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: icseri <icseri@student.your42network>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/18 18:00:25 by icseri            #+#    #+#             */
/*   Updated: 2024/02/19 10:05:54 by icseri           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	char_type(char x)
{
	if (x >= 'a' && x <= 'z')
		return ('l');
	else if (x >= 'A' && x <= 'Z')
		return ('u');
	else if (x >= '0' && x <= '9')
		return ('d');
	else
		return ('s');
}

char	*ft_strcapitalize(char *str)
{
	char	p;
	int		i;

	i = 0;
	p = ' ';
	while (str[i] != '\0')
	{
		if (char_type(str[i]) == 'l' && char_type(p) == 's')
		{
			str[i] = str[i] - 32;
		}
		else if (char_type(str[i]) == 'u' && char_type(p) != 's')
		{
			str[i] = str[i] + 32;
		}
		p = str[i];
		i++;
	}
	return (str);
}
