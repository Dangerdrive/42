void	rush(int x, int y);
/*a gente tem aqui a função rush, 
que tem como tipo de retorno void (vazio), que é usado quando não há um valor para retornar,
ou seja, vc não precisa colocar um valor de entrada pra ele te retornar algo. Ele dá uma saída independente disso.
na função rush, a gente tem duas variaveis declaradas como int (de numero inteiro).
 */
int		main()
/*aqui a gente tem o tipo de retorno int para a função main. Esse valor é 0 pra quando a função funciona corretamente, e 1 pra quando não funciona.
ou seja, vc não precisa colocar um valor de entrada pra ele te retornar algo. Ele dá uma saída independente disso.*/
{
	rush(8, 10);
//aqui a gente dá valores pras variaveis x e y, que são inteiros conforme declarado na rush.
	return (0);
	// retorno zero significa que o programa foi bem sucedido. 0 nesse caso é o inteiro retornada para função main. Essa linha não é necessária, pois se removida, esse retorno zero pra quando o programa dá certo fica implicita.
}
