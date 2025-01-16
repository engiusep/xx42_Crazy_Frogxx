/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:17:15 by engiusep          #+#    #+#             */
/*   Updated: 2025/01/16 19:11:20 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int check_stack_1(char **splt,int i)
{
	if(check_double(splt,i) == -1)
	{
			write(2,"Error\n",7);
			if(i == 1)
				free_all2(splt,ft_strlen_split(splt));
			exit(EXIT_FAILURE);
	} 
	if(check_stack(splt) == -1)
	{
		if(i == 1)
			free_all2(splt,ft_strlen_split(splt));
		write(2, "Error\n",7);
		return(1);
	}
	return (0);
}