// #include "cub3D.h"
// #include <math.h>

// #define PI		3.1415926535

// #define WIDTH	1024
// #define HEIGHT	512

// #define K_LEFT	123
// #define K_RIGHT	124
// #define K_UP	126
// #define K_DOWN	125

// #define ESC		53

// #define	BLACK	0x000000
// #define	BLANCO	0xFFF5F4

// #define	P_SIZE	12
// #define SPEED	10

// typedef struct	s_data {
// 	void	*win;
// 	void	*mlx;
// 	void	*img;
// 	char	*addr;
// 	int		bbp;
// 	int		line_l;
// 	int		endian;
// }				t_data;

// typedef struct s_jugador
// {
// 	float	px;
// 	float	py;
// 	float	pdx;
// 	float	pdy;
// 	float	pa;
// }			t_jugador;

// typedef struct	s_mapa
// {
// 	int			mapX;
// 	int			mapY;
// 	int			mapS;
// 	int			*map;
// }				t_mapa;

// typedef struct s_rayito
// {
// 	int		r;
// 	int		mx;
// 	int		my;
// 	int		mp;
// 	int		dof;
// 	float	rx;
// 	float	ry;
// 	float	ra;
// 	float	xo;
// 	float	yo;
// }			t_rayito;


// typedef	struct s_all
// {
// 	int			wall_size;
// 	t_jugador	jugador;
// 	t_data		data;
// 	t_mapa		map;
// 	t_rayito	ray;
// }				t_all;

// void	draw_player(t_data *data, t_jugador *jugador);
// void	create_world(t_all *all);

// static int exit_win(t_all *f)
// {
// 	if (f)
// 		mlx_destroy_window(f->data.mlx, f->data.win);
// 	exit(EXIT_SUCCESS);
// }

// static void	background_color(t_data *img, unsigned int color)
// {
// 	int i;

// 	i = 0;
// 	while (i < WIDTH * HEIGHT)
// 	{
// 		((unsigned int *)img->addr)[i] = color;
// 		i++;
// 	}
// }

// static void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_l + x * (data->bbp / 8));
// 	*(unsigned int*)dst = color;
// }

// static int	read_key(int key, t_all *all)
// {
// 	printf("(%f, %f)\n", all->jugador.px, all->jugador.py);
// 	if (key == K_LEFT) {
// 		all->jugador.pa -= 0.2;
// 		if (all->jugador.pa < 0) { all->jugador.pa += 2*PI; }
// 		all->jugador.pdx = cos(all->jugador.pa) * SPEED;
// 		all->jugador.pdy = sin(all->jugador.pa) * SPEED; 
// 	}
// 	if (key == K_RIGHT) {
// 		all->jugador.pa += 0.2;
// 		if (all->jugador.pa > 2*PI) { all->jugador.pa -= 2*PI; }
// 		all->jugador.pdx = cos(all->jugador.pa) * SPEED;
// 		all->jugador.pdy = sin(all->jugador.pa) * SPEED;
// 	}
// 	if (key == K_UP) {
// 		all->jugador.px += all->jugador.pdx;
// 		all->jugador.py += all->jugador.pdy;
// 	}
// 	if (key == K_DOWN) {
// 		all->jugador.px -= all->jugador.pdx;
// 		all->jugador.py -= all->jugador.pdy;
// 	}
// 	if (key == ESC)
// 		exit_win(all);
// 	create_world(all);

// 	return (0);
// }

// // void	draw_rays3D(t_all *all)
// // {
// // 	for (all->ray.r=0; all->ray.r<1; all->ray.r++)
// // 	{
// // 		all->ray.dof = 0;
// // 		float	aTan = -1/tan(all->ray.ra);
// // 		if (all->ray.ra > PI) { // looking down
// // 			all->ray.ry = (((int)all->jugador.py >> 6) << 6) - 0.0001;
// // 			all->ray.rx = (all->jugador.py - all->ray.ry) * aTan + all->jugador.px;
// // 			all->ray.yo = -64;
// // 			all->ray.xo = -all->ray.yo*aTan;
// // 		}
// // 		if (all->ray.ra < PI) { // looking up
// // 			all->ray.ry = (((int)all->jugador.py >> 6) << 6) + 64;
// // 			all->ray.rx = (all->jugador.py - all->ray.ry) * aTan + all->jugador.px;
// // 			all->ray.yo = 64;
// // 			all->ray.xo = -all->ray.yo*aTan;
// // 		}
// // 	}
// // }

// void	draw_player(t_data *data, t_jugador *jugador)
// {
// 	int startX = (int)jugador->px;
// 	int startY = (int)jugador->py;
// 	int playerColor = 0x800080;
		// free(game->player);
// 	float Y = startY + P_SIZE / 2;

// 	for (int i = 0; i <= steps; i++) {
// 		for (int j = 0; j < lineWidth; j++)
// 			my_mlx_pixel_put(data, (int)(X + j * cos(jugador->pa)), (int)(Y + j * sin(jugador->pa)), lineColor);
// 		X += Xinc;
// 		Y += Yinc;
// 	}
// }

// static void	guarda_mapa(t_all *all)
// {
// 	int map_values[100] = {
// 		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
// 		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
// 		1, 0, 0, 0, 0, 0, 0, 0, 0, 1,
// 		1, 0, 0, 0, 0, 1, 0, 0, 0, 1,
// 		1, 0, 0, 1, 1, 1, 0, 0, 0, 1,
// 		1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
// 		1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
// 		1, 0, 0, 1, 0, 0, 0, 0, 0, 1,
// 		1, 1, 1, 1, 1, 1, 1, 1, 1, 1,
// 	};

// 	for (int i = 0; i < all->map.mapX * all->map.mapY; i++) {
// 		all->map.map[i] = map_values[i];
// 	}
// }

// static void	crea_mapa(t_all *all)
// {
// 	int cols, rows;
// 	int startX = 0;
// 	int startY = 0;

// 	for (cols = 0; cols < all->map.mapY; cols++)
// 	{
// 		for (rows = 0; rows < all->map.mapX; rows++)
// 		{
// 			startX = rows * all->wall_size;
// 			startY = cols * all->wall_size;
// 			if (all->map.map[cols * all->map.mapX + rows] == 1)
// 			{
// 				for (int i = startX; i < startX + all->wall_size - 1; i++)
// 				{
// 					for (int j = startY; j < startY + all->wall_size - 1; j++)
// 							my_mlx_pixel_put(&all->data, i, j, BLACK);
// 				}
// 			}
// 			else
// 			{
// 				for (int i = startX; i < startX + all->wall_size - 1; i++)
// 				{
// 					for (int j = startY; j < startY + all->wall_size - 1; j++)
// 							my_mlx_pixel_put(&all->data, i, j, BLANCO);
// 				}
// 			}
// 		}
// 	}
// }
// void	create_world(t_all *all)
// {
// 	mlx_clear_window(all->data.mlx, all->data.win);
// 	background_color(&all->data, 0x808080);
// 	crea_mapa(all);
// 	draw_player(&all->data, &all->jugador);
// 	mlx_put_image_to_window(all->data.mlx, all->data.win, all->data.img, 0, 0);
// }

// static void	init_juego(t_all *all)
// {
// 	all->jugador.px = 400;
// 	all->jugador.py = 300;
// 	all->jugador.pdx = cos(all->jugador.pa) * 5;
// 	all->jugador.pdy = sin(all->jugador.pa) * 5;
// 	all->map.mapX = 10;
// 	all->map.mapY = 10;
// 	all->map.mapS = all->map.mapX * all->map.mapY;
// 	all->map.map = ft_calloc(sizeof(int), all->map.mapS);
// 	all->wall_size = WIDTH / (all->map.mapX * 2);
// 	guarda_mapa(all);
// 	all->ray.ra = all->jugador.pa;

// 	all->data.mlx = mlx_init();
// 	all->data.win = mlx_new_window(all->data.mlx, WIDTH, HEIGHT, "RAYCASTING");
// 	all->data.img = mlx_new_image(all->data.mlx, WIDTH, HEIGHT);
// 	all->data.addr = mlx_get_data_addr(all->data.img, &all->data.bbp, \
// 	&all->data.line_l, &all->data.endian);
// }

// int main(void)
// {
// 	t_all	all;

// 	init_juego(&all);
// 	create_world(&all);
// 	mlx_put_image_to_window(all.data.mlx, all.data.win, all.data.img, 0, 0);
// 	mlx_hook(all.data.win, 17, 0, exit_win, &all);
// 	mlx_hook(all.data.win, 2, 1L<<0, read_key, &all);
// 	// mlx_key_hook(all.data.win, read_key, &all);
// 	mlx_loop(all.data.mlx);
// }
