/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cgrasser <cgrasser@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 06:19:03 by cgrasser          #+#    #+#             */
/*   Updated: 2024/12/19 09:41:58 by cgrasser         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	usage(void)
{
	ft_printf("usage: ./fdf <file.fdf>\n");
	exit(1);
}

int	main(int argc, char *argv[])
{
	if (argc != 2)
		usage();
	fdf(argv[1]);
	return (0);
}
