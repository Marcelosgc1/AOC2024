#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unordered_map>
using namespace std;


void newStone(unsigned long long int stoneLabel, unsigned long long int qnt, unordered_map<unsigned long long int, unsigned long long int> &ns){

    if (stoneLabel==0){
        ns[1] += qnt;
        return;
    }


    char *aux = (char*) malloc(21 * sizeof(char));
    sprintf(aux, "%llu", stoneLabel);
    int tam = strlen(aux);

    if (tam%2!=0){ 
        ns[stoneLabel*2024] += qnt;
        
        return;
    }
    
    tam = tam/2;
    
    unsigned long long int n1, n2;
    sscanf(&(aux[tam]), "%llu", &n1);
    aux[tam]='\0';
    sscanf(aux, "%llu", &n2);

    ns[n1] += qnt;
    ns[n2] += qnt;
    return;

}



int main(int argc, char const *argv[]){
    
    unordered_map<unsigned long long int, unsigned long long int> nextStone;
    char c;
    char *aux = (char*)malloc(200 * sizeof(char));
    memset(aux, 0, 200 * sizeof(char));
    unsigned long long int num, it = -1;

    while ((c=getchar())!='\n'){
        if (c==' '){
            sscanf(aux, "%llu", &num);
            memset(aux, 0, 200 * sizeof(char));
            nextStone[num] += 1;
            it=-1;
        }else{
            aux[++it]=c;
        }        
    }
    sscanf(aux, "%llu", &num);
    memset(aux, 0, 200 * sizeof(char));
    nextStone[num] += 1;
    it=0;
    
    



    for (int j = 0; j < 75; j++){
        unordered_map<unsigned long long int, unsigned long long int> temp;
        for (auto x : nextStone){
            newStone(x.first, x.second, temp);
        }
        nextStone=temp;
    }
    for (auto x : nextStone){
        it+=x.second;
    }
    
    printf("\n\n%llu\n\n", it);

    return 0;
}
