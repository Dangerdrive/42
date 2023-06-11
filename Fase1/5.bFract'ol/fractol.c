
#include "fractol.h"

/* int handle_esc(int keycode, void *param, void *window)
{
    // Check if ESC key is pressed
    if (keycode == 53) // 53 is the keycode for ESC key
    {
        // Exit the program
        mlx_destroy_window(param, window); // Assuming `window` is your mlx window pointer
        exit(0);
    }

    return 0;
}

int	main(void)
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 720, 480, "Hello world!");

	    // Register key press callback function
    mlx_hook(mlx_win, 2, 1L << 0, handle_esc, mlx);

	mlx_loop(mlx);
} */


int handle_esc(int keycode, t_data *data)
{
    // Check if ESC key is pressed
    if (keycode == 65307) // 53 is the keycode for ESC key
    {
        // Exit the program
        //mlx_destroy_window(data->mlx, data->mlx_win);
        printf("ESC key was pressed\n");
        exit(0);
    }

    return 0;
}

int main(void)
{
    t_data  data;

    char    *win_name = "Fract'ol (soon)!";
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, WIN_WIDTH, WIN_HEIGHT, win_name);

    // Register key press callback function
    mlx_key_hook(data.mlx_win, handle_esc, &data);

    mlx_loop(data.mlx);
}


//https://en.wikipedia.org/wiki/List_of_fractals_by_Hausdorff_dimension
// Curve filling the Koch snowflake
// Von Koch in 3D