#include "mlx.h"

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

void	pixel_put(t_data *data, int x, int y, int color)
{
	char *dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

# define WIDTH 1920
# define HEIGHT 1080

# define TITLE "fdf"

int main()
{
	void	*mlx;
	t_data	img;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, WIDTH, HEIGHT, TITLE);

	img.img = mlx_new_image(mlx, WIDTH, HEIGHT);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	
	pixel_put(&img, WIDTH / 2, HEIGHT / 2, 0x00FFFF00);
	pixel_put(&img, WIDTH / 2 + 1, HEIGHT / 2, 0x00FFFF00);
	pixel_put(&img, WIDTH / 2 + 2, HEIGHT / 2, 0x00FFFF00);
	pixel_put(&img, WIDTH / 2 + 3, HEIGHT / 2, 0x00FFFF00);
	pixel_put(&img, WIDTH / 2 + 4, HEIGHT / 2, 0x00FFFF00);

	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);

	mlx_loop(mlx);
	
	return (0);
}