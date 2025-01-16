/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 11:22:08 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/16 18:58:40 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long int ft_atol(char *str)
{
	long int	number;
	long int	count;

	number = 0;
	count = 0;
	while ((*str >= 9 && *str <= 13) || (*str == 32))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			count++;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		number = number * 10 - (*str - '0');
		str++;
	}
	if (count % 2 != 1)
		return (-number);
	return (number);
}
int find_str(char *str, char *str2)
{
	int i;
	i = 0;
	
		while(str[i] == str2[i] && str[i] && str2[i])
		{
			if(str[i + 1] == '\0' && str2[i + 1] == '\0')
				return (1);
			i++;
		}
	return (0);
}

int check_double(char **str,int splt)
{
	int i;
	int j;
	int temp;
	j = 0;
	i = 0;
	while(str[i])
	{
		j = i + 1;
		while(str[j])
		{	
			if(find_str(str[i],str[j]) == 1)
			{
				return (-1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
int	check_stack(char **str)
{
	int i;
	int j;
	
	i = 0;
	j = 0;
	while(str[i])
	{
		j = 0;
		while(str[i][j] != '\0')
		{
			if(ft_isdigit(str[i][j]) == 1)
				j++;
			else if(str[i][j] == '-' && ft_isdigit(str[i][j + 1]) && j == 0)
				j++;
			else
				return(-1);
		}
		i++;
	}
	return(0);
}
int sorted(t_stack a)
{
	int i;
	i = 0;
	while(i < a.top)
	{
		if(a.arr[i] < a.arr[i + 1])
			return(0);
		i++;
	}
	return (1);
}
