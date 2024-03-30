#include <stdlib.h>
#include <stdio.h>

typedef struct s_point
{
    int x;
    int y;
} 		t_point;

void	check_square(int **area, t_point size, t_point iter, int *check)
{
	if ((iter.x < 1 || iter.x >= size.x - 1) || (iter.y < 1 || iter.y >= size.y - 1))
    {
        *check = 1;
        printf("entro\n");
        return;
    }
	if (area[iter.y - 1][iter.x] == 5 || area[iter.y + 1][iter.x] == 5)
		*check = 1;
	else if (area[iter.y][iter.x - 1] == 5 || area[iter.y][iter.x + 1] == 5)
		*check = 1;
	else if (area[iter.y - 1][iter.x - 1] == 5 || area[iter.y - 1][iter.x + 1] == 5)
		*check = 1;
	else if (area[iter.y + 1][iter.x + 1] == 5 || area[iter.y + 1][iter.x - 1] == 5)
		*check = 1;
}

void	checker(int **area, t_point size)
{
	t_point	iter = {0, 0};
	int		check = 0;

	while (iter.y < size.y && !check)
	{
		iter.x = 0;
		printf("------------------------- y = %d ----------------------------\n", iter.y);
		while (iter.x < size.x)
		{
			printf(" -----> OUT POS[%d][%d] = %d <-------\n", iter.y, iter.x, area[iter.y][iter.x]);
			if (area[iter.y][iter.x] == 0)
			{
				printf("POS[%d][%d] = %d\n", iter.y, iter.x, area[iter.y][iter.x]);
				check_square(area, size, iter, &check);
			}
			iter.x++;
		}
		iter.y++;
	}
	if (check)
		printf("\nERROR\n");
}

int **make_area(int **zone, t_point size)
{
    int **new = malloc(sizeof(int *) * size.y);
    for (int i = 0; i < size.y; ++i) {
        new[i] = malloc(sizeof(int) * size.x);
        for (int j = 0; j < size.x; ++j)
            new[i][j] = zone[i][j];
    }
    return new;
}

int main(void)
{
    t_point size = {9, 5};

    int *zone[] = {
		(int[]) {5, 1, 1, 1, 1, 1, 1, 1, 1},
		(int[]) {5, 1, 0, 0, 0, 1, 0, 0, 1},
		(int[]) {5, 1, 1, 0, 1, 1, 0, 0, 1},
		(int[]) {1, 1, 0, 0, 1, 0, 0, 0, 1},
		(int[]) {5, 1, 1, 1, 1, 1, 1, 1, 1}
    };

    int **area = make_area(zone, size);

    for (int i = 0; i < size.y; ++i)
	{
        for (int j = 0; j < size.x; ++j)
            printf("%d", area[i][j]);
        printf("\n");
    }
	printf("\n");
   
	checker(area, size);

    // Liberar memoria
    for (int i = 0; i < size.y; ++i)
        free(area[i]);
    free(area);

    return 0;
}
