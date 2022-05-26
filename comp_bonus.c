/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   comp_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yschecro <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/27 19:29:52 by yschecro          #+#    #+#             */
/*   Updated: 2022/05/24 15:37:51 by yschecro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcheck(char *s1, char *s2)
{
	int	i;

	i = 0;
	if (!s1 || !s2)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	if (!s1[i] && !s2[i])
		return (1);
	return (0);
}

char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	i = 0;
	s1 = malloc(sizeof(char) * ft_strlen(s2) + 1);
	if (!s1)
		return (NULL);
	while (s2[i])
	{
		s1[i] = s2[i];
		i++;
	}
	s1[i] = 0;
	return (s1);
}
