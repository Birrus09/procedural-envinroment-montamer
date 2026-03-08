//test game loop 
#include <iostream>
#include "Tamer.h"

using namespace std;


void menu(){
    cout << "0) quit, 1) create creature" << endl;
}


int main(){
    int opt;
    do{
        menu();
        cin >> opt;
        if (opt == 1){
            cout << "ciao" << endl; 
        }
    } while (opt != 0);

    return 0;
}
