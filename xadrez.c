#include <stdio.h>

#define BOARD_SIZE 8

void move_bishop(int x, int y) {
    printf("Movimentação do Bispo a partir de (%d, %d):\n", x, y);
    for (int i = 1; i < BOARD_SIZE; i++) {
        if (x + i < BOARD_SIZE && y + i < BOARD_SIZE) printf("(%d, %d)\n", x + i, y + i);
        if (x - i >= 0 && y - i >= 0) printf("(%d, %d)\n", x - i, y - i);
        if (x + i < BOARD_SIZE && y - i >= 0) printf("(%d, %d)\n", x + i, y - i);
        if (x - i >= 0 && y + i < BOARD_SIZE) printf("(%d, %d)\n", x - i, y + i);
    }
}

void move_rook(int x, int y) {
    printf("Movimentação da Torre a partir de (%d, %d):\n", x, y);
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (i != x) printf("(%d, %d)\n", i, y);
        if (i != y) printf("(%d, %d)\n", x, i);
    }
}

void move_queen(int x, int y) {
    printf("Movimentação da Rainha a partir de (%d, %d):\n", x, y);
    move_bishop(x, y);
    move_rook(x, y);
}

void move_knight(int x, int y) {
    int moves[8][2] = {{2,1}, {2,-1}, {-2,1}, {-2,-1}, {1,2}, {1,-2}, {-1,2}, {-1,-2}};
    printf("Movimentação do Cavalo a partir de (%d, %d):\n", x, y);
    for (int i = 0; i < 8; i++) {
        int nx = x + moves[i][0], ny = y + moves[i][1];
        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE)
            printf("(%d, %d)\n", nx, ny);
    }
}

int main() {
    int x = 3, y = 3; // Posição inicial para teste
    move_bishop(x, y);
    move_rook(x, y);
    move_queen(x, y);
    move_knight(x, y);
    return 0;
}
