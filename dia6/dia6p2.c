#include <stdio.h>


char **novaMatriz(char **m1, int col, int lin){
    char **m2 = malloc(100000 * sizeof(char *));

    for (int i = 0; i <= col; i++){
        m2[i] = malloc(1000 * sizeof(char));
        for (int j = 0; j <= lin; j++){
            m2[i][j]=m1[i][j];
        }
    }
    return m2;
}

char **novaMatriz2(int col, int lin){
    char **m2 = malloc(100000 * sizeof(char *));

    for (int i = 0; i <= col; i++){
        m2[i] = malloc(1000 * sizeof(char));
        for (int j = 0; j <= lin; j++){
            m2[i][j]='.';
        }
    }
    return m2;
}

int main(int argc, char const *argv[]){
    

    char c;
    int col = 0, lin = -1;
    int posx, posy;
    char **matrizOriginal = malloc(100000 * sizeof(char *));
    matrizOriginal[col] = malloc(1000 * sizeof(char));
    while ((c = getchar()) != EOF){
        if (c == '\n'){
            col++;
            lin=-1;
            matrizOriginal[col] = malloc(1000 * sizeof(char));
        }else{
            matrizOriginal[col][++lin] = c;
            if (c=='^'){
                posx=col;
                posy=lin;
                matrizOriginal[col][lin] = '.';
            }
            
        }
    }
    int contador = 0;
    int direcaox=-1;
    int direcaoy=0;
    int initX=posx, initY=posy;
    char **matrix = novaMatriz(matrizOriginal, col, lin);
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

    
    int sum = 0;
    for (int i = 0; i <= col; i++){
        for (int j = 0; j <= lin; j++){
            if (matrix[i][j]!='x' || (i==initX && j==initY)){
                continue;
            }
            char **vis = novaMatriz2(col, lin);
            char **nm = novaMatriz(matrizOriginal, col, lin);
            nm[i][j]='#';
            posx=initX;
            posy=initY;
            int flag = 0;
            int direcaox=-1;
            int direcaoy=0;
            int flagOrigin=0;
            int contDir = 0;
            
            while (posx>-1 && posx<=col && posy>-1 && posy<=lin){     
                
                switch (nm[posx][posy]){
                    case '.':
                        nm[posx][posy] = '+';
                        if (direcaoy==-1){
                            vis[posx][posy] = 'a';
                        }else if (direcaox==1){
                            vis[posx][posy] = 'b';
                        }else if (direcaoy==1){
                            vis[posx][posy] = 'c';
                        }else if (direcaox==-1){
                            vis[posx][posy] = 'd';
                        }
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
                        posx+=direcaox;
                        posy+=direcaoy;
                        break;
                    case '+':
                        if (direcaoy==-1 && vis[posx][posy] == 'a'){
                            flag=1;
                        }else if (direcaox==1 && vis[posx][posy] == 'b'){
                            flag=1;
                        }else if (direcaoy==1 && vis[posx][posy] == 'c'){
                            flag=1;
                        }else if (direcaox==-1 && vis[posx][posy] == 'd'){
                            flag=1;
                        }
                        posx+=direcaox;
                        posy+=direcaoy;
                        break;
                    default:
                        break;
                }
                if (flag){
                    printf("\n-%d %d-",i,j);
                    sum+=1;
                    break;
                }
                
            }
        
        }
        
    }
    







    
    printf("\n\nnum: %d\n\n", contador);
    printf("\n\nsum: %d\n\n", sum);






    
    return 0;
}
