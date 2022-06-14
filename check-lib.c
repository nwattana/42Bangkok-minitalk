/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nwattana <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 17:09:45 by nwattana          #+#    #+#             */
/*   Updated: 2022/06/14 08:28:32 by nwattana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	main(int argc,char *argv[])
{
	if (argc == 2)
		ft_printf("%s\n",argv[1]);

	ft_printf("%%c: %c\n", 'T');
	ft_printf("%%s: %s\n", "this is string");
	ft_printf("%%p: %#p\n", argv);
	ft_printf("%%d: %d\n", -42);
	ft_printf("%%u: %u\n", 42);
	ft_printf("%%i: %i\n", -42);
	ft_printf("%%x: %x\n", 42);
	ft_printf("%%X: %X\n", 42);
}
