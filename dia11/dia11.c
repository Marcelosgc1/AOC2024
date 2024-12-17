#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int newStone(long int stoneLabel, int blinks){
    
    if (blinks==25) return 1;
    
    if (!stoneLabel) return newStone(1L, blinks+1);


    char *aux = malloc(20 * sizeof(char));
    sprintf(aux, "%ld", stoneLabel);
    int tam = strlen(aux);

    if (tam%2!=0) return newStone(stoneLabel*2024L,blinks+1);
    tam = tam/2;
    
    long int n1, n2;
    sscanf(&(aux[tam]), "%ld", &n1);
    aux[tam]='\0';
    sscanf(aux, "%ld", &n2);
    
    return newStone(n1, blinks+1) + newStone(n2, blinks+1);    
}



int main(int argc, char const *argv[]){
    

    char c;
    char *aux = malloc(200 * sizeof(char));
    memset(aux, 0, 200 * sizeof(char));
    long int len = -1, it = -1, *arr = malloc(200 * sizeof(long int));

    while ((c=getchar())!='\n'){
        if (c==' '){
            sscanf(aux, "%ld", &arr[++len]);
            memset(aux, 0, 200 * sizeof(char));
            it=-1;
        }else{
            aux[++it]=c;
        }        
    }
    sscanf(aux, "%ld", &arr[++len]);
    memset(aux, 0, 200 * sizeof(char));
    it=0;

    for (int j = 0; j <= len; j++){
        it += newStone(arr[j], 0);
    }
    printf("\n\n%ld\n\n", it);

    return 0;
}
