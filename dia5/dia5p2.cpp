#include <stdio.h>
#include <stdlib.h>
#include <map>
#include <list>
#include <vector>
#include <sstream>
#include <iostream> // Required for cin and getline

using namespace std;

int main(int argc, char const *argv[]) {
    int x, y;
    map<int, list<int>> paginas;

    
    while (scanf("%d|%d", &x, &y) == 2) {
        paginas[x].push_back(y);
    }

    int sum = 0;
    vector<int> lista;
    string line;

    
    cin.ignore(); 
    while (getline(cin, line)) {
        if (line.empty()) break;

        
        stringstream ss(line);
        string token;
        lista.clear();

        while (getline(ss, token, ',')) {
            lista.push_back(stoi(token));
        }
        

        
        bool flag = true, solve = false;
        int len = lista.size();
        while (!solve){
            solve = true;
            for (int i = len-1; i > 0; i--) {
                for (int j = i-1; j >= 0; j--) {
                    for (int v : paginas[lista[i]]) {
                        if (v == lista[j]) {
                            flag = false;
                            solve = false;
                            int aux = lista[i];
                            lista[i] = lista[j];
                            lista[j] = aux;
                            
                            break;
                        }
                    }
                    if (!solve) break;
                }
                if (!solve) break;
            }
        }

        if (!flag) {
            if (len%2==1){
                sum += lista[len / 2]; 
            }else{
                sum += lista[(len-1) / 2];
            }
            
             
        }
    }

    printf("\n\nnum: %d\n\n", sum);

    
    for (const auto& [key, values] : paginas) {
        printf("%d: ", key);
        for (int v : values) {
            printf("%d ", v);
        }
        printf("\n");
    }

    return 0;
}
