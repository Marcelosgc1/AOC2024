#include <stdio.h>



int main(int argc, char const *argv[]){
    

    char c;
    int col = 0, lin = -1;
    int posx, posy;
    char **matrix = malloc(100000 * sizeof(char *));
    matrix[col] = malloc(1000 * sizeof(char));
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            col++;
            lin=-1;
            matrix[col] = malloc(1000 * sizeof(char));
        }else{
            matrix[col][++lin] = c;
            if (c=='^'){
                posx=col;
                posy=lin;
                matrix[col][lin] = '.';
            }
            
        }
    }
    int contador = 0;
    int direcaox=-1;
    int direcaoy=0;
    while (posx>-1 && posx<=col && posy>-1 && posy<=lin){
        
        switch (matrix[posx][posy]){
        case '.':
            contador++;
            matrix[posx][posy] = 'x';
            posx+=direcaox;
            posy+=direcaoy;
            break;
        case 'x':
            posx+=direcaox;
            posy+=direcaoy;
            break;
        case '#':
            posx-=direcaox;
            posy-=direcaoy;
            if (direcaoy==-1){
                direcaoy = 0;
                direcaox = -1;
            }else if (direcaox==1){
                direcaoy = -1;
                direcaox = 0;
            }else if (direcaoy==1){
                direcaoy = 0;
                direcaox = 1;
            }else if (direcaox==-1){
                direcaoy = 1;
                direcaox = 0;
            }
            break;
        default:
            break;
        }
    }
    

    printf("\n\nsum: %d\n\n", contador);






    
    return 0;
}
