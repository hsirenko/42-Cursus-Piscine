/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfabbian <lfabbian@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 15:25:40 by lfabbian          #+#    #+#             */
/*   Updated: 2023/01/08 11:04:48 by lfabbian         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	int fd;

	if (argc == 2)
	{
		fd = ft_read_fd(argv[1]);
		ft_printf("GNL 1: %s", get_next_line(fd));
		env_init();
	}
	else
		ft_printf("Wrong number of args");
}
