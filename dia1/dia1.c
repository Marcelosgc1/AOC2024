#include <stdio.h>
#include "extra.h"


int main(int argc, char const *argv[]){
    
    int *a = malloc(1000000 * sizeof(int));
    int *b = malloc(1000000 * sizeof(int));
    
    int x, y, i = -1;
    scanf("%d %d", &x, &y);
    while (x != -1){
        i++;
        a[i] = x;
        b[i] = y;
        scanf("%d %d", &x, &y);
    }
    
    quickSort(&a, 0, i);
    quickSort(&b, 0, i);

    int sum = 0;
    for (int j = 0; j <= i; j++){
        int aux = a[j] - b[j];
        if (aux<0) aux = aux * -1;
        sum = sum + aux;
    }
    printf("%d\n", sum);
    

    return 0;
}
