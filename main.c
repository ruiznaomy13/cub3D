#include <stdio.h>
#include "mlx/mlx.h"

#define SCR_W 640
#define SCR_H 480

int	main()
{
	void	*mlx;
	void	*mlx_win;

	mlx = mlx_init();
	mlx_new_window(mlx, SCR_W, SCR_H, "TASTE");
	mlx_loop(mlx);
}