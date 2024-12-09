#include <stdio.h>




int main(int argc, char const *argv[]){
    
    char c;
    int st = 0, it = -1, sum = 0;
    char *num1 = malloc(3*sizeof(char));
    char *num2 = malloc(3*sizeof(char));

    while ((c=getchar()) != EOF){
        if (it>3){
            st = 0;
            it = -1;
        }
        switch (st){
        case 0:
            if(c=='m') st++;
            
            break;
        case 1:
            if(c=='u') st++;
            else st = 0;
            break;
        case 2:
            if(c=='l') st++;
            else st = 0;
            break;
        case 3:
            if(c=='(') st++;
            else st = 0;
            break;
        case 4:
            do{
                if (c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6' && c!='7' && c!='8' && c!='9'){
                    it = -1;
                    st = 0;
                    num1 = malloc(3*sizeof(char));
                    break;
                }else{
                    num1[++it] = c;
                }
            }while((c=getchar()) != ',');
            it = -1;
            st++;
            break;
        case 5:
            do{
                
                if (c!='0' && c!='1' && c!='2' && c!='3' && c!='4' && c!='5' && c!='6' && c!='7' && c!='8' && c!='9'){
                    it = -1;
                    st = 0;
                    num2 = malloc(3*sizeof(char));
                    break;
                }else{
                    num2[++it] = c;
                }
            }while((c=getchar()) != ')');
            if (c == ')'){
                int x, y;
                sscanf(num1, "%d", &x);
                sscanf(num2, "%d", &y);
                sum += x*y;
                st = 0;
            }
            num1 = malloc(3*sizeof(char));
            num2 = malloc(3*sizeof(char));
            it = -1;
            st = 0;
            break;
        default:
            break;
        }
    }
    printf("\n%d\n", sum);
    return 0;
}
