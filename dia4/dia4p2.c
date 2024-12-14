#include <stdio.h>

int findXmas(char ***matriz, int l, int c, int col, int lin){
    int sum = 0;
    int LIMITE_DIREITO = l - 1;
    int LIMITE_ESQUERDO_SUPERIOR = 1;
    int LIMITE_INFERIOR = c - 1;

    if (lin >= LIMITE_ESQUERDO_SUPERIOR && lin <= LIMITE_DIREITO && col >= LIMITE_ESQUERDO_SUPERIOR && col <= LIMITE_INFERIOR){
        sum +=  (*matriz)[col+1][lin+1]=='M' &&
                (*matriz)[col+1][lin-1]=='M' &&
                (*matriz)[col-1][lin+1]=='S' &&
                (*matriz)[col-1][lin-1]=='S';

        sum +=  (*matriz)[col+1][lin+1]=='S' &&
                (*matriz)[col+1][lin-1]=='S' &&
                (*matriz)[col-1][lin+1]=='M' &&
                (*matriz)[col-1][lin-1]=='M';

        sum +=  (*matriz)[col+1][lin+1]=='S' &&
                (*matriz)[col+1][lin-1]=='M' &&
                (*matriz)[col-1][lin+1]=='S' &&
                (*matriz)[col-1][lin-1]=='M';

        sum +=  (*matriz)[col+1][lin+1]=='M' &&
                (*matriz)[col+1][lin-1]=='S' &&
                (*matriz)[col-1][lin+1]=='M' &&
                (*matriz)[col-1][lin-1]=='S';
    }
    
    return sum;

}





int main(int argc, char const *argv[]){
    

    char c;
    int col = 0, lin = -1;
    char **matrix = malloc(100000 * sizeof(char *));
    matrix[col] = malloc(1000 * sizeof(char));
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            col++;
            lin=-1;
            matrix[col] = malloc(1000 * sizeof(char));
        }else{
            matrix[col][++lin] = c;
        }
    }
    int sum = 0;
    for (int i = 0; i <= col; i++){
        for (int j = 0; j <= lin; j++){
            if (matrix[i][j]=='A'){
                sum += findXmas(&matrix,lin,col,i,j);
            }
            
        }
        
    }
    
    printf("\n%d\n", sum);
    return 0;
}
