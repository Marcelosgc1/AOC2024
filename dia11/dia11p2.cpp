//couldnt solve


// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include <unordered_map>
// using namespace std;


// long long int newStone(long long int stoneLabel, int blinks, unordered_map<long long int, pair<long long int, long long int>> &ns){
//     if (stoneLabel==-1) return 0;
//     if (blinks==75) return 1;
//     pair<long long int, long long int> stones;
//     try{
//         stones = ns.at(stoneLabel);   
//     }
//     catch(const std::exception& e){
//         if (!stoneLabel){
//             ns[stoneLabel] = make_pair(1,-1);
//             return newStone(1L, blinks+1, ns);
//         }
    

//         char *aux = (char*) malloc(20 * sizeof(char));
//         sprintf(aux, "%lld", stoneLabel);
//         int tam = strlen(aux);

//         if (tam%2!=0){ 
//             ns[stoneLabel] = make_pair(stoneLabel*2024L,-1);
//             return newStone(stoneLabel*2024L,blinks+1,ns);
//         }

//         tam = tam/2;
        
//         long long int n1, n2;
//         sscanf(&(aux[tam]), "%lld", &n1);
//         aux[tam]='\0';
//         sscanf(aux, "%lld", &n2);
//         ns[stoneLabel] = make_pair(n1,n2);
//         return newStone(n1, blinks+1,ns) + newStone(n2, blinks+1,ns);  
//     }
//     return newStone(stones.first, blinks+1, ns) + newStone(stones.second, blinks+1, ns);
// }



// int main(int argc, char const *argv[]){
    
//     unordered_map<long long int, pair<long long int, long long int>> nextStone;
//     char c;
//     char *aux = (char*)malloc(200 * sizeof(char));
//     memset(aux, 0, 200 * sizeof(char));
//     long long int len = -1, it = -1, *arr = (long long int*)malloc(200 * sizeof(long long int));

//     while ((c=getchar())!='\n'){
//         if (c==' '){
//             sscanf(aux, "%lld", &arr[++len]);
//             memset(aux, 0, 200 * sizeof(char));
//             it=-1;
//         }else{
//             aux[++it]=c;
//         }        
//     }
//     sscanf(aux, "%lld", &arr[++len]);
//     memset(aux, 0, 200 * sizeof(char));
//     it=0;
    
    



//     for (int j = 0; j <= len; j++){
//         it += newStone(arr[j], 0, nextStone);
//     }
//     printf("\n\n%lld\n\n", it);

//     return 0;
// }
