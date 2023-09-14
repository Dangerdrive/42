#include "fractol.h"

static void	data_init(t_fractal *fractal)
{
	fractal->escape_value = 4;
	fractal->iterations = 4000;
	fractal->x_shift = 0.0;
	fractal->y_shift = 0.0;
}

void	fractal_init(t_fractal *fractal)
{
fractal->mlx = mlx_init(WIDTH, HEIGHT, fractal->name, true);//tentar ver com alguem qual a diferença, já que o init aqui já cria a janela. Criar um item mlx connection na struct?
	if(!fractal->mlx)
		exit(EXIT_FAILURE); // (da documentação)
fractal->img = mlx_new_image(fractal->mlx, WIDTH, HEIGHT);
	if(!fractal->img)
		{
			//mlx_close_window(fractal.mlx);--
			mlx_terminate(fractal->mlx); //um dos dois ou os dois?
			exit(EXIT_FAILURE);// confirmar se esse seria o jeito certo de dar free
		}
//events_init(fractal);
data_init(fractal);
}











/*
diferenças minilibx e MLX codam
mlx_init -> mlx_init_window
mlx_init da codam já cria a janela, enquanto a da minilibx não. A da minilibx só cria a conexão.
então ela recebe parametros para a criação da janela também.

as structs de imagem são diferentes. Você nao tem uma mlx_get_address pra modificar valores da imagem.

typedef struct mlx_image
{
	const uint32_t	width;
	const uint32_t	height;
	uint8_t*		pixels;
	mlx_instance_t*	instances;
	size_t			count;
	bool			enabled;
	void*			context;
}	mlx_image_t;


*/

























