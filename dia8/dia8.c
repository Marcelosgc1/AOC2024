#include <stdio.h>
#include <stdlib.h>




int main(int argc, char const *argv[]){
    
    char c;
    int coluna=-1, linha=-1;
    char **matrix = malloc(1000 * sizeof(char));
    matrix[++coluna] = malloc(1000 * sizeof(char));

    char **visi = malloc(1000 * sizeof(char));
    visi[coluna] = malloc(1000 * sizeof(char));

    while ((c=getchar())!=EOF){
        if (c=='\n'){
            matrix[++coluna] = malloc(1000 * sizeof(char));
            visi[coluna] = malloc(1000 * sizeof(char));
            linha=-1;
            continue;
        }

        matrix[coluna][++linha]=c;
        visi[coluna][linha] = '.';
        
    }

    int sum = 0;
    for (int i = 0; i <= coluna; i++){
        for (int j = 0; j <= linha; j++){
            
            if (matrix[i][j]=='.'){
                continue;
            }

            for (int k = 0; k <= coluna; k++){
                for (int l = 0; l <= linha; l++){
                    
                    if (matrix[i][j]!=matrix[k][l] || (i==k  && j==l)){
                        continue;
                    }


                    int a = (i*2) - k;
                    int b = (j*2) - l;
                    if(a>-1 && a <= coluna && b>-1 && b <= linha){
                        sum += visi[a][b] != '#';
                        visi[a][b] = '#';
                    }
                    
                }
            }
        }   
    }
    
    printf("\n\nsum: %d\n\n", sum);

    return 0;
}
