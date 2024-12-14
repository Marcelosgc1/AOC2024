#include <stdio.h>

int findXmas(char ***matriz, int l, int c, int col, int lin){
    int sum = 0;
    int a = lin; 
    int b = col;
    int LIMITE_DIREITO = l - 3;
    int LIMITE_ESQUERDO = 3;
    int LIMITE_INFERIOR = c - 3;
    int LIMITE_SUPERIOR = 3; 
           

    if (lin >= LIMITE_ESQUERDO){
        sum += (*matriz)[col][--lin]=='M' && (*matriz)[col][--lin]=='A' && (*matriz)[col][--lin]=='S';
        lin = a;
    }
    
    if (lin <= LIMITE_DIREITO){
        sum += (*matriz)[col][++lin]=='M' && (*matriz)[col][++lin]=='A' && (*matriz)[col][++lin]=='S';
        lin = a;
    }

    if (col <= LIMITE_INFERIOR){
        sum += (*matriz)[++col][lin]=='M' && (*matriz)[++col][lin]=='A' && (*matriz)[++col][lin]=='S';
        col = b;
    }
    
    if (col >= LIMITE_SUPERIOR){
        sum += (*matriz)[--col][lin]=='M' && (*matriz)[--col][lin]=='A' && (*matriz)[--col][lin]=='S';
        col = b;
    }


    if (lin >= LIMITE_ESQUERDO && col >= LIMITE_SUPERIOR){
        sum += (*matriz)[--col][--lin]=='M' && (*matriz)[--col][--lin]=='A' && (*matriz)[--col][--lin]=='S';
        lin = a;
        col = b;
    }
    if (lin >= LIMITE_ESQUERDO && col <= LIMITE_INFERIOR){
        sum += (*matriz)[++col][--lin]=='M' && (*matriz)[++col][--lin]=='A' && (*matriz)[++col][--lin]=='S';
        lin = a;
        col = b;
    }
    
    if (lin <= LIMITE_DIREITO && col >= LIMITE_SUPERIOR){
        sum += (*matriz)[--col][++lin]=='M' && (*matriz)[--col][++lin]=='A' && (*matriz)[--col][++lin]=='S';
        lin = a;
        col = b;
    }
    if (lin <= LIMITE_DIREITO && col <= LIMITE_INFERIOR){
        sum += (*matriz)[++col][++lin]=='M' && (*matriz)[++col][++lin]=='A' && (*matriz)[++col][++lin]=='S';
        lin = a;
        col = b;
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
            if (matrix[i][j]=='X'){
                sum += findXmas(&matrix,lin,col,i,j);
            }
            
        }
        
    }
    
    printf("\n%d\n", sum);
    return 0;
}
