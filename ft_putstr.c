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

int	ft_putnbr(int n)
{
	int	count;
	long	nb; //long pour le int min

	nb = n;
	if (nb < 0)
	{
		count += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		count += ft_putnbr(/*(int)*/nb / 10); //recursive (100 -> 10 -> 1)
	}
	count += ft_putchar((nb % 10) + 48);
	return (count);
}

int	ft_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	ft_putunbr(unsigned int n) // pas en unsigned car il n'est pas 
					       // demandé dans l'ex, on l'utilise juste pour compter
{
	unsigned int	temp; //sert de copie pour les divisions sans affecter
				  //le n de base
	unsigned int	div; //pour le diviseur
	int		count;

	div = 1;
	temp = n;
	if (temp == 0) //évite d'entrer dans la focntion pour rien et print que 0
	{
		count += ft_putchar('0');
		return (1);
	}
	while (temp >= 10) //cherche le plus grand diviseur ex: 42 -> 10, 420 -> 100
			 //permet de lire de gauche à droite 4 puis 2 puis 0
	{
		temp = temp / 10;
		div = div * 10;//lui trouve le plus grand diviseur en multipliant
			       //le nmbr de fois que tu divises a peu près
	}
	while (div > 0)//tant qu'il affiche qql chose
	{
		count += ft_putchar(n / div);//ici div est déjà le plus grand
						  //diviseur, ex: n = 420 -> div = 100
						  //420 / 100 = 4+0=4
		n %= div;//420 % 100=20
		div /= 10;//100/10= 10 (comme 20) et ensuite il fait des tours
			  //jusqu'à afficher 420
	}
	return (count);
}

int	ft_puthex_lower(unsigned int n)
{
    unsigned int	last_digit;
    char		hex_char;
    int			count;

    count = 0;
    if (n >= 16)//16 c'est base hexadecimal, ici si on a plus d'1 chiffre hex
    {
        count += ft_puthex_lower(n / 16);//récursif
    }
    last_digit = n % 16;//dernier 'chiffre', ce qu'il reste
    if (last_digit < 10)//vérifie si c'est un décimal de 0 à 9 car présents dans ASCII
    {
        hex_char = last_digit + 48;//48+4 par ex =52 -> ASCII de '4'
    }
    else //si pas entre 0 et 9, donc de 10 à 15
    {
        hex_char = last_digit - 10 + 97;//-10 pour ramener à 0 ou 5 en hexa,
					//la marge de 0 à 5 à partir de 97 c'est
					//tout pile la marge entre 'a' et 'f'*
					//donc lastd(decimal) = 12 -> 
					//12-10=2,97+2=99 -> c
    }
    count += ft_putchar(hex_char);//écrit
    return (count);
}

int ft_puthex_upper(unsigned int n)
{
    unsigned int    last_digit;
    char            hex_char;
    int             count;

    count = 0;
    if (n >= 16)
    {
        count += ft_puthex_upper(n / 16);
    }
    last_digit = n % 16;
    if (last_digit < 10)
    {
        hex_char = last_digit + '0';
    }
    else
    {
        hex_char = last_digit - 10 + 'A';
    }
    count += ft_putchar(hex_char);
    return (count);
}

//ça c'est pour le putptr, à regarder si tu peux pas juste laisser un en long long
int ft_puthex_lower(unsigned long long n)
{
    unsigned int    last_digit;
    char            hex_char;
    int             count;

    count = 0;
    if (n >= 16)
    {
        count += ft_puthex_upper(n / 16);
    }
    last_digit = n % 16;
    if (last_digit < 10)
    {
        hex_char = last_digit + '0';
    }
    else
    {
        hex_char = last_digit - 10 + 97;
    }
    count += ft_putchar(hex_char);
    return (count);
}

int ft_putptr(void *ptr)//pour les ptr on est en 64bits donc on a besoin de plus d'espace
{
    unsigned long long  address;
    int                 count;

    count = 0;
    if (!ptr)
    {
        write(1, "(nil)", 5);
        return (5);
    }
    address = (unsigned long long)ptr;//caster parce que void *
    count += ft_putchar('0');
    count += ft_putchar('x');
    count += ft_puthex_lower(address); 
    return (count);
}

#include <stdarg.h>
#include <unistd.h>

int ft_handle_specifier(char specifier, va_list ap)
{
    int count;

    count = 0;
    if (specifier == 'c')
        count += ft_putchar(va_arg(ap, int));
    else if (specifier == 's')
        count += ft_putstr(va_arg(ap, char *));
    else if (specifier == 'd' || specifier == 'i')
        count += ft_putnbr(va_arg(ap, int));
    else if (specifier == 'u')
        count += ft_putunsigned(va_arg(ap, unsigned int));
    else if (specifier == 'x')
        count += ft_puthex_lower(va_arg(ap, unsigned int));
    else if (specifier == 'X')
        count += ft_puthex_upper(va_arg(ap, unsigned int));
    else if (specifier == 'p')
        count += ft_putptr(va_arg(ap, void *));
    else if (specifier == '%')
        count += ft_putchar('%');
    return (count);
}

//regarde c'est quoi va-list etc
int ft_printf(const char *format, .../*nbr indéfini d'arguments*/)
{
    va_list ap;
    int     i;
    int     count;

    i = 0;
    count = 0;
    va_start(ap, format);
    while (format[i])
    {
        if (format[i] == '%')
        {
            i++;
            count += ft_handle_specifier(format[i], ap);
        }
        else
        {
            count += ft_putchar(format[i]);
        }
        i++;
    }
    va_end(ap);
    return (count);
}
