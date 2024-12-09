#include <stdio.h>


int comparisson(int a, int b, int c, int *dampenerFlag, int sf, int *cresc){
    if (sf == 0 && b>a){
        (*cresc) = -1;
    }
    if (sf == 1 && b==c){
        if (b>a){
            (*cresc) = -1;
        }else{
            (*cresc) = 1;
        }
    }
    
    int diff = (a - b) * (*cresc);
    if (!(0 < diff && diff < 4)){ //unsafe
        if ((*dampenerFlag)){
            return 0;
        }
                    
        if ((*dampenerFlag) == 0){    
            (*dampenerFlag) = 1;
            return comparisson(a, c, c, dampenerFlag, sf, cresc);
        }

    }
    return 1;
}


int main(int argc, char const *argv[]){

    int sum = 0;
    int y;

    while (scanf("%d", &y) != EOF){ 
        int x;
        char c;

        int *arr = malloc(10 * sizeof(int));
        int iterator = 0;
        arr[iterator] = y;

        while (scanf("%d%c", &x, &c)){
            arr[++iterator] = x;
            if (c=='\n'){
                break;
            }  
        }

        int t = 1;

        for (int i = 0; i <= iterator; i++){
            t = 1;
            int multiplicador = 0;
            for (int j = 0; j < iterator; j++){
                if (i==j){
                    continue;
                }

                int next = j+1;

                if (next==i && ++next>iterator) continue;                

                if (!multiplicador){
                    if (arr[j]>arr[next]){
                        multiplicador=1;
                    }else{
                        multiplicador=-1;
                    }
                }
                int diff = (arr[j]-arr[next]) * multiplicador;
                if (!(0 < diff && diff < 4)){
                    t = 0;
                    break;
                }
                
                
            }
            if (t){

                break;
            }
            
        }
        



        // if (t){
        //     printf("safe\n");
        // }else{
        //     printf("unsafe\n");
        // }
        
        
        sum = sum + t;
    }

    printf("%d\n", sum);



    return 0;
}



