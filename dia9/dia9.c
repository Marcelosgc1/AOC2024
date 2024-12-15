#include <stdio.h>
#include <stdlib.h>


int main(int argc, char const *argv[]){
    
    char c;
    long long int *disco = malloc(10000000*sizeof(long long int));
    long long int it = -1;
    long long int count = 0;
    long long int value = -1;
    long long int temp;
    long long int space;

    FILE *file = fopen("input.txt", "r");

    while ((c=fgetc(file))!=EOF){
        space = c - '0';

        if (count%2==0) temp = ++value;
        else temp = -1;

        for (long long int i = 0; i < space; i++){
            disco[++it]=temp;
        }
        count++;
    }
    printf("\n\nc:%lld,it:%lld,v:%lld\n\n", count, it, value);
    long long int len = it + 1;
    long long int sum = 0;
    // for (int j = 0; j < len; j++){
    //     printf("%lld,", disco[j]);
    // }
    // printf("\n\n");
    for (long long int i = 0; i < len; i++){
        if (disco[i]>=0){
            sum += i * disco[i];
            continue;
        }
        while (disco[it]<0 && it>i){
            it--;
        }
          
        disco[i]=disco[it];
        disco[it]=-1;
        if (it<=i || disco[i]<0) break;
        sum += i * disco[i];
    }
    
    // for (long long int j = 0; j < len; j++){
    //     if (disco[j]<0) break;
    //     sum += j * disco[j];
    // }
    
    
    printf("\n\nsum: %lld\n\n", sum);
    // for (int i = 0; i < len; i++){
    //     printf("%lld,", disco[i]);
    // }
    // printf("\n\n");
    fclose(file);

    return 0;
}
