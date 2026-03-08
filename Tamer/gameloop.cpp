//test game loop 
#include <iostream>
#include "Tamer.h"
//[atk, def, matk, mdef, spd, hp]

using namespace std;


void menu(){
    cout << "0) quit, 1) see creature status" << endl;
}


int main(){
    int opt;
    do{
        menu();
        cin >> opt;
        if (opt == 1){
            UpdateXpTreshold(cerbiatto_instance);
            cout << "Creature Status:" << endl
            << "Name: " << cerbiatto_instance.name << endl
            << "Level: " << cerbiatto_instance.lvl << endl
            << "HP: " << cerbiatto_instance.hp << "/" << cerbiatto_instance.hpmax << endl
            << "Mana: " << cerbiatto_instance.mana << endl
            << "XP: " << cerbiatto_instance.xp << "/" << cerbiatto_instance.xp_treshold << endl
            << "Stats: " << endl
            << "atk: " << cerbiatto_instance.stats[0] << endl
            << "def: " << cerbiatto_instance.stats[1] << endl
            << "matk: " << cerbiatto_instance.stats[2] << endl
            << "mdef: " << cerbiatto_instance.stats[3] << endl
            << "spd: " << cerbiatto_instance.stats[4] << endl;
        }
    } while (opt != 0);

    return 0;
}
