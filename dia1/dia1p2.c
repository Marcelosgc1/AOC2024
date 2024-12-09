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
    int valorAnterior = -1;
    int qnt = 0;
    int ponteiro = 0;

    for (int j = 0; j <= i; j++){
        if (valorAnterior == a[j]) {
            sum += valorAnterior * qnt;
            continue;
        }

        qnt = 0;
        for (int k = ponteiro; k <= i; k++){
            if (b[k]>a[j]){
                ponteiro = k;
                break;
            }
            if (b[k] == a[j]){
                qnt++;
            }            
        }

        sum += a[j] * qnt;
        valorAnterior = a[j];
    }
    printf("%d\n", sum);
    

    return 0;
}
