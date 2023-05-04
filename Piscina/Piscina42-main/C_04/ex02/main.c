#include <unistd.h>

void	ft_putnbr(int nb);

int	main(void)
{
	ft_putnbr(-2147483648);
	write(1,"\n",1);
	ft_putnbr(2147483647);
	write(1,"\n",1);
	ft_putnbr(1);
	write(1,"\n",1);
	ft_putnbr(0);
	write(1,"\n",1);
	return (0);
}

/*

a funçao vai passando pelos if, e se for maior que 10, chama ela mesmo com o valor de nb/10. Ela vai continuar fazendo isso enquanto o resultado for >10.
ou seja, pra nb =432, ele vai passar uma vez, nao vai ate o fim do código e chama a si mesmo de novo, dessa vez com nb = 43.
Ele faz isso de novo, sem ir até o final da funçao,

Conforme ele nao vai até o fim da funçao, a parte que tá abaixo da onde a função chama a si mesmo "acumula", 
e será aplicada 1x mais para cada vez que a funçao teve que chamar a si propria.
Ou seja, as linhas abaixo ainda estao pendente de rodar + 2x.
		nb = nb % 10;
		}
	if (nb < 10) ft_putchar(nb + '0');

Na 3a vez que a funçao recomeça, nb está valendo 4.
Como 4 < 10, ele vai para o terceiro if, passa pelo 
nb = nb % 10; e 4 % 10 = 4.
 e printa o numero 4 usando write.

Dai ele volta pra outra instancia da recursao, em que o valor ainda valia 43. Ai ela volta para nb = nb % 10;
43 % 10 = 3
entao ele printa o três.

Entao ele volta pra uma outra instancia que nb  = 432, e 432 % 10 = 2.
Entao ele printa o 2 e termina de rodar o programa.


void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11); //special case handling
		return;
	}
	if (nb < 0)
		{
		ft_putchar('-'); //is it negative?
		nb = -nb;
		}
	if (nb >= 10)
		{
		ft_putnbr(nb / 10);
		nb = nb % 10;
		}
	if (nb < 10) ft_putchar(nb + '0');
}
*/