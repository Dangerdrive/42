//
//#include "fractol.h"
//
//void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
//{
//	char	*dest;
//
//	dest = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
//	*(unsigned int*)dest = color;
//}
//
//
//int handle_esc(int keycode, t_data *data)
//{
//	// Check if ESC key is pressed
//	if (keycode == 65307) // 53 is the keycode for ESC key
//	{
//		// Exit the program
//		//mlx_destroy_window(data->mlx, data->mlx_win);
//		printf("ESC key was pressed\n");
//		exit(0);
//	}
//
//	return 0;
//}
//
//int main(void)
//{
//	t_data  data;
//	int x = 50;
//	int y = 50;
//	long long color = 0x00FF0000;
//
//	char	*win_name = "Fract'ol (soon)!";
//	data.mlx = mlx_init();
//	data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, win_name);
//	data.img = mlx_new_image(data.mlx, WIN_WIDTH, WIN_HEIGHT);
//
//	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,
//								 &data.endian);
//	while (x < 400)
//	{
//			while (y < 400)
//			{
//				my_mlx_pixel_put(&data, x, y, color);
//				y++;
//			}
//		x++;
//	}
//	mlx_put_image_to_window(data.mlx, data.mlx_win, data.img, 0, 0);
//
//	// Register key press callback function
//	mlx_key_hook(data.mlx_win, handle_esc, &data);
//
//	mlx_loop(data.mlx);
//}
//

//https://en.wikipedia.org/wiki/List_of_fractals_by_Hausdorff_dimension
// Curve filling the Koch snowflake
// Von Koch in 3D-Wall -Wextra -Werror -I/usr/include -Imlx_linux -O3 -c $< -o $@

#include "fractol.h"


// Exit the program as failure.
static void ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

// Print the window width and height.
static void ft_hook(void* param)
{
	const mlx_t* mlx = param;

	printf("WIDTH: %d | HEIGHT: %d\n", mlx->width, mlx->height);
}

int32_t	main(void)
{
	int y = 2;
	int x = 2;
	uint32_t color = 0xFF0000FF;

	// MLX allows you to define its core behaviour before startup.
	mlx_set_setting(MLX_MAXIMIZED, false);
	mlx_t* mlx = mlx_init(WIDTH, HEIGHT, "Fract'ol (soon)", true);
	if (!mlx)
		ft_error();

	/* Do stuff */

	// Create and display the image.
	mlx_image_t* img = mlx_new_image(mlx, 256, 256);
	if (!img || (mlx_image_to_window(mlx, img, 50, 30) < 0))
		ft_error();

	// Even after the image is being displayed, we can still modify the buffer.
	while (x < 500)
	{
		y = 1;
		while (y < 20)
		{
			mlx_put_pixel(img, x, y++, color);
		}
		x++;
	}
	x = 1;
	y = 1;
	while (y < 300)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
	x = 255;
	y = 1;
	while (y < 300)
	{
		mlx_put_pixel(img, x, y, color);
		y++;
	}
	x = 1;
	y = 254;
	while (x < 255)
	{
			mlx_put_pixel(img, x, y, color);
		x++;
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);

//	 Register a hook and pass mlx as an optional param.
//	 NOTE: Do this before calling mlx_loop!
//	mlx_loop_hook(mlx, ft_hook, mlx);

}
