#include <stdio.h>
#include <stdlib.h>









int main(int argc, char const *argv[]){
    
    char c;
    long long int *disco = malloc(5000000*sizeof(long long int));
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
    long long int tam = it + 1;
    long long int sum = 0;
    // for (int j = 0; j < tam; j++){
    //     printf("%lld,", disco[j]);
    // }
    // printf("\n\n");
    long long int flag = 0;
    int len = -1;
    
    for (long long int i = it; i > -1; i--){
        if (disco[i]>=0 && (flag==disco[i] || flag == 0)){
            flag = disco[i];
            len++;
            continue;
        }
        if (!flag) continue;
        
        int count = -1;
        for (long long int j = 0; j <= i; j++){
            if (disco[j]>=0){
                count = -1;
                continue;
            }
            if (++count == len){
                // i++;
                while (len>=0){
                    disco[j-len]=disco[i+1+len];
                    disco[i+1+len]=-1;
                    len--;
                }
                break;
            }
        }
        i++;
        flag=0;
        len=-1;
        
    }
    
    
    for (long long int k = 0; k < tam; k++){
        if (disco[k]<0) continue;
        sum += k * disco[k];
    }
    
    
    printf("\n\nsum: %lld\n\n", sum);
    // for (int i = 0; i < tam; i++){
    //     printf("%lld,", disco[i]);
    // }
    // printf("\n\n");
    fclose(file);

    return 0;
}
