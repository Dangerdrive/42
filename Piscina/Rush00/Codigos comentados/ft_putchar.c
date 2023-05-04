#include <unistd.h>
//aqui a gente inclui a biblioteca unistd.h, que contém a função write que a gente vai usar.

void	ft_putchar(char c)
/* void pq nao retorna nenhum valor, e ai a gente a função ft_putchar, com um argumento char de nome c. */
{
	write(1, &c, 1);
}


