/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: engiusep <engiusep@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/09 11:00:55 by engiusep          #+#    #+#             */
/*   Updated: 2025/09/09 13:06:17 by engiusep         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>


int	main(int argc,char **argv)
{
	int i;
	int j;

	i = 1;
	j = 0;
	
	std::string str;
	
	if(argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}

	while(i < argc)
	{
		j = 0;
		while(argv[i][j])
			str += std::toupper(argv[i][j++]);
		i++;
	} 
	std::cout << str << std::endl;
	return (0);
}
