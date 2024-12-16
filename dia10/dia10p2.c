#include <stdio.h>
#include <stdlib.h>





int path(char **matriz, int col, int lin, int l, int c, char value){
    if (!(col>-1 && col<=c && lin>-1 && lin<=l) || matriz[col][lin]!=value){
        return 0;
    }
    if (matriz[col][lin]=='9'){
        return 1;
    }
    value+=1;
    return 
        path(matriz, col+1, lin, l, c, value) +
        path(matriz, col, lin+1, l, c, value) +
        path(matriz, col-1, lin, l, c, value) +
        path(matriz, col, lin-1, l, c, value);
        
    
}




int main(int argc, char const *argv[]){
    



    char c;
    char **matriz = malloc(1000 * sizeof(int));
    matriz[c] = malloc(1000 * sizeof(int));
    int col=0, lin=-1;
    while ((c=getchar())!=EOF){
        if (c=='\n'){
            lin=-1;
            matriz[++col] = malloc(1000 * sizeof(int)); 
        }else{
            matriz[col][++lin]=c;
        }       
    }
    int sum = 0;
    for (int i = 0; i <= col; i++){
        for (int j = 0; j <= lin; j++){
            if (matriz[i][j]!='0') continue;
            sum += path(matriz, i, j, lin, col, '0');
            // for (int k = 0; k <= col; k++){
            //     for (int l = 0; l <= lin; l++){
            //         if (matriz[k][l]==',') matriz[k][l]='9';            
            //     }
            // }
                    
        }
    }
    printf("\n\nsum: %d\n\n", sum);


    return 0;
}
