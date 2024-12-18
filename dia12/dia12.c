#include <stdio.h>
#include <stdlib.h>
// #include <glib-2.0/glib.h>



int findRegion(int **matriz, int ***visitados, int l, int c, int i, int j, int *count, int value){

    if (!(i>-1 && i <= c && j>-1 && j <= l) || value != matriz[i][j]) return 1;
    if ((*visitados)[i][j]) return 0;
    (*count)++;
    (*visitados)[i][j] = 1;
    return  findRegion(matriz, visitados, l, c, i+1, j, count, value) +
            findRegion(matriz, visitados, l, c, i, j+1, count, value) +
            findRegion(matriz, visitados, l, c, i-1, j, count, value) +
            findRegion(matriz, visitados, l, c, i, j-1, count, value);
}



int main(int argc, char const *argv[]){
    
    char c;
    int **matrix = malloc(10000 * sizeof(int));
    int **visitados = malloc(10000 * sizeof(int));
    int col=0, lin=-1;
    matrix[col] = malloc(10000 * sizeof(int));
    visitados[col] = malloc(10000 * sizeof(int));
    // int *areas = malloc(100 * sizeof(int));
    // int *perim = malloc(100 * sizeof(int));
    // memset(areas, 0, 100 * sizeof(int));
    // memset(perim, 0, 100 * sizeof(int));
    
    while ((c=getchar())!=EOF){
        if (c=='\n'){
            matrix[++col] = malloc(10000 * sizeof(int));
            visitados[col] = malloc(10000 * sizeof(int));
            lin=-1;
        }else{
            matrix[col][++lin] = (int) c;
            visitados[col][lin] = 0;
        }
    }
    int sum = 0, aux = 0;
    for (int i = 0; i <= col; i++){
        for (int j = 0; j <= lin; j++){
            if (visitados[i][j]==0){
                int type = matrix[i][j];
                sum += findRegion(matrix, &visitados, lin, col, i, j,&(aux), type) * aux;
            }
            aux = 0;
        }
    }
    
    // for (int i = 0; i < 100; i++){
    //     sum += perim[i] * areas[i];
    // }
    printf("\n\n%d\n\n", sum);
    
    


    return 0;
}
