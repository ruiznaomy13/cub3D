#include "lib/cub3D.h"

#define SCR_W 640
#define SCR_H 480

static int	ft_error(int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(CYAN"\nSomething went wrong!\n\n");
	return (error);
}

int	check_input_map(char **av)
{
	ft_printf("%s\n", av[1]);
	return (0);
}

int	main(int ac, char *av[])
{
	/* void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, SCR_W, SCR_H, "cubu3D");
	mlx_loop(mlx);*/
	if (ac != 2)
		return (ft_error(EXIT_FAILURE));
	check_input_map(av);
	// store_map();
}
