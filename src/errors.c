/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: devjorginho <devjorginho@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 14:04:52 by devjorginho       #+#    #+#             */
/*   Updated: 2025/06/13 14:51:44 by devjorginho      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minitalk.h"

int	invalid_arguments(void)
{
	ft_putstr("Error: Please, enter a valid PID and a single message");
		return (1);
}
int	print_invalid_pid(void)
{
	ft_putstr("Error: you provided an invalid PID (-1). This may cause serious issues.\n");
	return (1);
}

