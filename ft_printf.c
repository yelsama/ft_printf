/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymohamed <ymohamed@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 11:25:42 by ymohamed          #+#    #+#             */
/*   Updated: 2022/08/06 14:25:59 by ymohamed         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putunsinint_fd(unsigned int u, int fd, int *n)
{
	if (u > 9)
	{
		*n += 1;
		ft_putunsinint_fd(u / 10, fd, n);
	}
	u = (u % 10) + 48;
	write(fd, &u, 1);
}

static void	ft_printhex(size_t val, char *base, int *n)
{
	if (val > 15)
	{
		*n = *n + 1;
		ft_printhex(val / 16, base, n);
	}	
	write(1, &base[val % 16], 1);
}

static int	on_action2(int *i, char *argdefiner, va_list argu)
{
	int	n;

	n = 0;
	if (argdefiner[*i] == 'c')
		ft_putchar_fd(va_arg(argu, int), 1);
	else if (argdefiner[*i] == 'u')
		ft_putunsinint_fd(va_arg(argu, unsigned int), 1, &n);
	else if (argdefiner[*i] == 'x')
		ft_printhex(va_arg(argu, long int), "0123456789abcdef", &n);
	else if (argdefiner[*i] == 'X')
		ft_printhex(va_arg(argu, long int), "0123456789ABCDEF", &n);
	else if (argdefiner[*i] == '%')
		write(1, "%", 1);
	else if (argdefiner[*i] == 'p')
	{
		ft_putstr_fd("0x", 1);
		n = 2;
		ft_printhex((t_ul)va_arg(argu, void *), "0123456789abcdef", &n);
	}
	return (n);
}

static int	on_action(int *i, char *argdefiner, va_list argu)
{
	void	*p;
	int		n;
	int		m;

	n = 0;
	if (argdefiner[*i] == 's')
	{	
		p = (char *)va_arg(argu, int *);
		ft_putstr_fd(p, 1);
		n = ft_strlen(p) - 1;
	}
	else if (argdefiner[*i] == 'd' || argdefiner[*i] == 'i')
	{
		m = va_arg(argu, int);
		ft_putnbr_fd(m, 1);
		if (m != 0)
			n = -1;
		while (m != 0 && ++n)
				m /= 10;
	}
	else
		n = on_action2(i, argdefiner, argu);
	return (n);
}

int	ft_printf(const char *s, ...)
{
	va_list	atached_arg;
	char	*p;
	char	*cases;
	int		i;
	int		n;

	p = (char *)s;
	cases = "cspdiuxX%";
	i = -1;
	n = 0;
	va_start(atached_arg, s);
	while (p[++i] && ++n)
	{
		if (p[i] != '%')
			write(1, &p[i], 1);
		else if (p[i] == '%' && ft_strchr(cases, p[i + 1]))
		{
			i++;
			n += on_action(&i, p, atached_arg);
		}
	}
	va_end(atached_arg);
	return (n);
}
