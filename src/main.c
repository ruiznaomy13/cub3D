#include "lib/cub3D.h"

static int	ft_error(int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(CYAN"\nSomething went wrong!\n\n");
	return (error);
}

int	check_input_map(char **av, t_game *game)
{
	save_map(av, game->map);
	ft_printf("%s\n", av[1]);
	return (EXIT_SUCCESS);
}

int	init_game(char **av, t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));

	check_input_map(av, game);
	// store_map();
	return (EXIT_SUCCESS);
}
int	main(int ac, char *av[])
{
	t_game	game;

	/* void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, SCR_W, SCR_H, "cubu3D");
	mlx_loop(mlx);*/
	if (ac != 2)
		return (ft_error(EXIT_FAILURE));
	init_game(av, &game);
}
