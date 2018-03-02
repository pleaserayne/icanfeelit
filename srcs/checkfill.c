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
/*      "checkfill.c"  by:  pleaserayne  <boris.sabelfeld@code.berlin>        */    
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
int g_gc = 0;

int	open_error(int fd)
{
	if (fd == -1)
	{
		ft_putstr("open() error\n");
		return (0);
	}
	return (1);
}

int	close_err(int fd)
{
	if (close(fd) == -1)
	{
		ft_putstr("close() error\n");
		return (0);
	}
	return (1);
}

int ft_check_buffer(char *str, int br)
{

	if (str[4] != '\n' || str[9] != '\n' || str[14] != '\n' || str[19] != '\n')
		return (0);
	if (br == 21)
		if (str[20] != '\n')
			return (0);
	if (ft_check_characters(str) == 0)
		return (0);
	return (1);	
}

int	ft_check_characters(char *str)
{
	int i;
	int n;
	int count;

	count = 0;
	n = 4;
	i = 0;
	while (n < 21)
	{
		while (i < n)
		{
			if (str[i] != '#' && str[i] != '.')
				return (0);
			if (str[i] == '#')
				count++;
			i++;
		}
		i++;
		n += 5;
	}
	if (count != 4)
		return (0);
	return (1);
}

int	ft_check_connections(char **str, int y, int x)
{
	int connections;

	connections = 0;
	if (x > 0)
	{
		if (str[y][x - 1] == '#')
			connections++;
	}
	if (x < 3)
	{
		if (str[y][x + 1] == '#')
			connections++;
	}
	if (y > 0)
	{
		if (str[y - 1][x] == '#')
			connections++;
	}
	if (y < 3)
	{
		if (str[y + 1][x] == '#')
			connections++;
	}
	return (connections);
}

void	ft_min(t_tetri *fuck, int y, int x, int pound)
{
	if (pound == 1)
	{
		fuck->miny = y;
		fuck->minx = x;
	}
	else
	{
		if (y < fuck->miny)
			fuck->miny = y;
		if (x < fuck->minx)
			fuck->minx = x;
	}
}

void	ft_max(t_tetri *fuck, int y, int x, int pound)
{
	if (pound == 1)
	{
		fuck->maxy = y;
		fuck->maxx = x;
	}
	else
	{
		if (y > fuck->maxy)
			fuck->maxy = y;
		if (x > fuck->maxx)
			fuck->maxx = x;
	}
}

int		ft_setletter(t_tetri *fuck)
{
	if (g_gc == 26)
		return (0);
	fuck->letter = 'A' + g_gc;
	g_gc++;
	return (1);
}

int	check_valid(t_tetri *fuck, char **store)
{
	int i;
	int n;
	int pounds;
	int connections;

	connections = 0;
	pounds = 0;
	i = 0;
	n = 0;
	while (store[n] != 0)
	{
		while (store[n][i] != '\0')
		{
			if (store[n][i] == '#')
			{
				pounds++;
				connections += ft_check_connections(store, n, i);
				ft_min(fuck, n, i, pounds);
				ft_max(fuck, n, i, pounds);
			}
			i++;
		}
		i = 0;
		n++;
	}
	if (ft_setletter(fuck) == 0)
		return (0);
	if (connections == 6 || connections == 8)
		return (1);
	return (0);
}
/* 2018/03/01                                                                 */
/* ************************************************************************** */