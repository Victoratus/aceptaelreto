#include <stdlib.h>
#include <stdio.h>
#include <stack>

using namespace std;

typedef struct Coor{
    short row, col;
};

void increment(char **data, short row, short col) {
    if (data[row][col] == '-') {
        data[row][col] = '1';
    } else if (data[row][col] != '*') {
        data[row][col]++;
    }
}

void enumerate(char **data, stack <Coor> s, short num_rows, short num_cols) {
    Coor aux_coor;
    while (!s.empty()) {
        aux_coor = s.top();
        s.pop();
        if (aux_coor.row - 1 >= 0) {        //The coordinate has a superior row
            if (aux_coor.col - 1 >= 0) {
                increment(data, aux_coor.row-1, aux_coor.col-1);
            }
            if (aux_coor.col + 1 < num_cols) {
                increment(data, aux_coor.row-1, aux_coor.col+1);
            }
            increment(data, aux_coor.row-1, aux_coor.col);
        }
        if (aux_coor.row + 1 < num_rows) {        //The coordinate has an inferior row
            if (aux_coor.col - 1 >= 0) {
                increment(data, aux_coor.row+1, aux_coor.col-1);
            }
            if (aux_coor.col + 1 < num_cols) {
                increment(data, aux_coor.row+1, aux_coor.col+1);
            }
            increment(data, aux_coor.row+1, aux_coor.col);
        }
        if (aux_coor.col - 1 >= 0) {        //Checking left and right
            increment(data, aux_coor.row, aux_coor.col-1);
        }
        if (aux_coor.col + 1 < num_cols) {
            increment(data, aux_coor.row, aux_coor.col+1);
        }
    }
}

void see(char **data, short rows, short cols, short row, short col, char **seen) { //Problem here, the function must be processing many times the same tiles, 'if' solution?
    seen[row][col] = '1';
    if (data[row][col] == '-') {
        if (row + 1 < rows) {
            if (col + 1 < cols) {
                if (seen[row+1][col+1] != '1') see(data, rows, cols, row+1, col+1, seen);
            }
            if (col - 1 >= 0) {
                if (seen[row+1][col-1] != '1') see(data, rows, cols, row+1, col-1, seen);
            }
            if (seen[row+1][col] != '1') see(data, rows, cols, row+1, col, seen);
        }
        if (row - 1 >= 0) {
            if (col + 1 < cols) {
                if (seen[row-1][col+1] != '1') see(data, rows, cols, row-1, col+1, seen);
            }
            if (col - 1 >= 0) {
                if (seen[row-1][col-1] != '1') see(data, rows, cols, row-1, col-1, seen);
            }
            if (seen[row-1][col] != '1') see(data, rows, cols, row-1, col, seen);
        }
        if (col + 1 < cols) {
            if (seen[row][col+1] != '1') see(data, rows, cols, row, col+1, seen);
        }
        if (col - 1 >= 0) {
            if (seen[row][col-1] != '1') see(data, rows, cols, row, col-1, seen);
        }
    }
}

int main() {
    char **data = NULL;
    char **seen = NULL;
    short rows = 0, cols = 0;
    short row, col;
    char aux;
    Coor coor;
    char gameover;
    int i, j;
    stack <Coor> s;

    while(true) {
        for (i = 0; i < rows; i++) free(data[i]);
        if (rows != 0) free(data);
        for (i = 0; i < rows; i++) free(seen[i]);
        if (rows != 0) free(seen);

        scanf("%hd %hd", &rows, &cols);
        scanf("%c", &aux);

        if (feof(stdin)) return 0;

        data = (char **) malloc(rows*sizeof(char *));
        for (i = 0; i < rows; i++) data[i] = (char *) malloc(cols*sizeof(char));
        seen = (char **) malloc(rows*sizeof(char *));
        for (i = 0; i < rows; i++) seen[i] = (char *) calloc(cols, sizeof(char));
        while(!s.empty()) s.pop();
        gameover = '0';

        for (i = 0; i < rows; i++) {
            for (j = 0; j < cols; j++) {
                scanf("%c", &data[i][j]);
                if (data[i][j] == '*') {
                    coor.row = i;
                    coor.col = j;
                    s.push(coor); 
                }
            }
            scanf("%c", &aux);
        }

        enumerate(data, s, rows, cols);

        scanf("%d", &j);
        for (i = 0; i < j; i++) {
            scanf("%hd %hd", &row, &col);
            if (data[row-1][col-1] == '*') {
                gameover = '1';
                break;
            }
            see(data, rows, cols, row-1, col-1, seen);
        }
        if (gameover == '1') {
            printf("GAME OVER\n");
        } else {
            for (i = 0; i < rows; i++) {
                for (j = 0; j < cols; j++) {
                    if (seen[i][j] == '1') printf("%c", data[i][j]);
                    else printf("X");
                }
                printf("\n");
            }
        }
    }
}