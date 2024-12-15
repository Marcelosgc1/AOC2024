#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumOrTimes(int *arr, int it, int temp, int len, int value){

    if (len<it){
        return temp == value;
    }
    
    return 
        sumOrTimes(arr, it+1, temp + arr[it], len, value) ||
        sumOrTimes(arr, it+1, temp * arr[it], len, value);

}



int main(int argc, char const *argv[]){
    
    long int num;
    int it, len;
    char c;
    char *arr = malloc(20 * sizeof(char));
    int *numArr = malloc(40 * sizeof(int));

    
    long long int sum = 0;

    while (scanf("%ld: ",&num)==1){
        it = -1;
        len = -1;
        memset(arr, 0, 20*sizeof(char));
        memset(numArr, 0, 40*sizeof(int));
        while ((c=getchar())!='\n'){
            if (c!=' '){
                arr[++it]=c;
                continue;
            }
            sscanf(arr, "%d", &numArr[++len]);
            memset(arr, 0, 20*sizeof(char));
            it = -1;
        }
        sscanf(arr, "%d", &numArr[++len]);
        if(sumOrTimes(numArr, 1, numArr[0], len, num)){
            sum += num;
        }
    }
    
    printf("\n\nsum: %lld\n\n", sum);

    return 0;
}
