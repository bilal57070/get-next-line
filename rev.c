salut jr siis
ddje jfr
rfjjfggjrf
ss******************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsafi <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 11:34:30 by bsafi             #+#    #+#             */
/*   Updated: 2023/02/10 11:45:27 by bsafi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

char *ft_rev(char *str)	
{
	int	i;

	i = 0;
	while(str[i] != '\0')
	{
		i++;
	}
	while(i > 0)
	{
		i--;
		write(1, &str[i], 1);
	}
	return (str);
}

int	main()
{
	char	a[] = "bilel";
	ft_rev(a);
}
