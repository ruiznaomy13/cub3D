#include <stdio.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

char mapa[ROWS][COLS] = {
    "01111",
    "11111",
    "11111",
    "11111",
    "11111"
};

bool is_surrounded_by_ones() {
    int i, j;
    bool visited[ROWS][COLS] = {false};

    int dr[] = {1, -1, 0, 0};
    int dc[] = {0, 0, 1, -1};

    // Find all starting points
    for (i = 1; i < ROWS - 1; i++) {
        for (j = 1; j < COLS - 1; j++) {
            if (mapa[i][j] == '1' && !visited[i][j]) {
                // Perform BFS
                int queue[ROWS * COLS][2];
                int front = 0, rear = 0;
                int r, c;

                queue[rear][0] = i;
                queue[rear][1] = j;
                rear++;

                visited[i][j] = true;

                while (front < rear) {
                    r = queue[front][0];
                    c = queue[front][1];
                    front++;

                    for (int k = 0; k < 4; k++) {
                        int new_r = r + dr[k];
                        int new_c = c + dc[k];

                        if (new_r >= 0 && new_r < ROWS && new_c >= 0 && new_c < COLS &&
                            mapa[new_r][new_c] == '1' && !visited[new_r][new_c]) {
                            queue[rear][0] = new_r;
                            queue[rear][1] = new_c;
                            rear++;

                            visited[new_r][new_c] = true;
                        }
                    }
                }
            }
        }
    }

    // Check if any visited point is on the border
    for (i = 0; i < ROWS; i++) {
        if (mapa[i][0] == '1' || mapa[i][COLS - 1] == '1') return false;
    }
    for (j = 0; j < COLS; j++) {
        if (mapa[0][j] == '1' || mapa[ROWS - 1][j] == '1') return false;
    }

    return true;
}

int main() {
    if (is_surrounded_by_ones()) {
        printf("El área está completamente rodeada de unos.\n");
    } else {
        printf("El área no está completamente rodeada de unos.\n");
    }
    return 0;
}
