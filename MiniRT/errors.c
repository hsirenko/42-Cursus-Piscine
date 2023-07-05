/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brisly <brisly@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/05 10:05:59 by brisly            #+#    #+#             */
/*   Updated: 2023/07/05 10:06:00 by brisly           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../incs/minirt.h"

int	print_error(char *error_message)
{
	ft_printf("\033[31m%s\033[30m\n", error_message);
	exit (EXIT_FAILURE);
}