/* ************************************************************************** */
/*                                                                            */
/*              ''''''''      ''''  ''''        ''''''''     ''''''''         */
/*           :.:.:.:.:     .:.:      :.:.      :.:.:.:.:    .:.:.:.:.         */
/*          :::         ::::          ::::    :::    ::::  ::                 */
/*         +:+       :+:+              :+:+  :+:     :+:  :+:+:+:+:           */
/*        #+#       +#+#              +#+#  +#+     +#+  +#+#+#+#+            */
/*       +#+         #+#+          #+#+    #+#    +#+#  #+                    */
/*      #########     ####      ####      #########    #########              */
/*       ########      ####  ####        ########     ######## .berlin        */
/*      ______________________________________________________________        */
/*      ____________UNIVERSITY OF APPLIED SCIENCES BERLIN_____________        */
/*                                                                            */
/*      "miscfill .c"  by:  pleaserayne  <boris.sabelfeld@code.berlin>        */    
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void ft_putchar(char c)
{
	write(1, &c, 1);
}
/* 2018/03/01                                                                 */
/* ************************************************************************** */