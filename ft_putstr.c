#include <unistd.h>

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	if (!str)
	{
		write(1, "(NULL)", 6);
		return (6);
	}
	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

void	ft_putnbr(int n, int *count)
{
	long	nb; //long pour le int min

	nb = n;
	if (nb < 0)
	{
		ft_putchar('-', count);
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(/*(int)*/(nb / 10), count); //recursive (100 -> 10 -> 1)
	}
	ft_putchar((nb % 10) + 48, count);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

void	ft_putunbr(unsigned int n, int *count) // pas en unsigned car il n'est pas demandé dans l'ex, on l'utilise juste pour compter
{
	unsigned	int temp; //
	unsigned	int div; //pour le diviseur

	div = 1;
	temp = n;
	if (temp == 0) //évite d'entrer dans la focntion pour rien et print que 0
	{
		ft_putchar('0', count);
		return ;
	}
	while (nb >= 10) //cherche le plus grand diviseur ex: 42 -> 10, 420 -> 100
			 //permet de lire de gauche à droite 4 puis 2 puis 0
	{
		nb = nb / 10;
		div = div * 10;
	}
	while (div > 0)
	{
		ft_pucthar((n / div) + 48, count);
		n % div;
		div / 10;
	}
}
