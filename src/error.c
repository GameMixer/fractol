/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gderenzi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 12:07:05 by gderenzi          #+#    #+#             */
/*   Updated: 2017/05/04 13:08:12 by gderenzi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fract_ol.h"

void	fract_error_malloc(void)
{
	ft_putstr("malloc error\n");
	exit(1);
}

void	fract_error_usage(char *str)
{
	ft_putstr(str);
	exit(2);
}
