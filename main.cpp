//user interface and program cycle

#include <iostream>
#include <vector>
#include "noise_gen.h"
#include "world_processing.h"

using namespace std;


void menu(){
    cout << "0) quit, 1) test random" << endl;
}

int main(){
    int opt;
    do{
        menu();
        cin >> opt;
        if (opt == 1){
            int seed = 0;
            cin >> seed;
            for (int i = 0; i < 100; i++)
            {
                cout << randomnum(seed) << endl;
            }
        }
    } while (opt != 0);

    return 0;
}
