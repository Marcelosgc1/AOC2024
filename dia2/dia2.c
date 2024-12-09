#include <stdio.h>



int main(int argc, char const *argv[]){

    int sum = 0;
    int y;

    while (scanf("%d", &y) != EOF){    
    
        int t = 1;
        int x;
        int flag = -1;
        int cresc = 1;
        char c;

        while (scanf("%d%c", &x, &c)){            
            if (flag == -1){
                flag = 1;
                if (y>x){
                    cresc = -1;
                }
                
            }

            int diff = (x - y) * cresc;
            y = x;

            if (!(0 < diff && diff < 4)){
                t = 0;
            }

            if (c=='\n'){
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



