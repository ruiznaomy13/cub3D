#include "lib/cub3D.h"

static int	ft_error(int error)
{
	if (error == EXIT_FAILURE)
		ft_printf(CYAN"\nSomething went wrong!\n\n");
	else if(error == E_SYNTAX)
		ft_printf("Bad map structure\nTry with a different map 😛");
	return (error);
}

int check_map_name(char *map_file)
{
	int	len;

	len = ft_strlen(map_file);
	if (len < 4 || ft_strncmp(map_file + len - 4, ".cub", 4) != 0)
		return (1);
	return (0);
}

int	check_input_map(char *map_file, t_game *game)
{
	// char	*line;
	// int		fd;
	// char	**map_array;

	// fd = open(map_file, O_RDONLY);
	// line = get_next_line(fd);
	(void)game;
	if (!check_map_name(map_file))
		return (ft_error(EXIT_FAILURE));
	// while (line)
	// {
	// 	if (game->checker == 0)
	// 		save_textures(map_file);
	// 	else (game->checker == 1)
	// 		save_map(map_file, game);
	// 	else
	// 		return (ft_error(E_SYNTAX));
	// }
	ft_printf("Game saved correctly!");
	return (EXIT_SUCCESS);
}

int	init_game(char *map_file, t_game *game)
{
	game = ft_calloc(1, sizeof(t_game));

	check_input_map(map_file, game);
		// save_map(map_file, game->map);
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
	init_game(av[1], &game);
}
