//test game loop 
#include <iostream>
#include "battle.h"
//[atk, def, matk, mdef, spd, hp]

using namespace std;


void menu(){
    cout << "0) quit, 1) see creature status, 2) see creature2 status, 3) check initialization, 4) add 100xp to c2, 5) test battle" << endl;
}


int main(){
    //init
    Load_Moveset("mosse.txt", global_moveset);
    cout << "test xp and lvl stuff: " << endl;

    for (int i = 0; i < instance_vector_DEBUG.size(); i++){
        instance_vector_DEBUG[i]->levelup();
        cout << instance_vector_DEBUG[i]->name << ": " << instance_vector_DEBUG[i]->xp << "/" << instance_vector_DEBUG[i]->xp_treshold << " xp" << endl;
    }

    int opt;

    do{
        menu();
        cin >> opt;
        if (opt == 1){
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
            //print moveset
            cout << "Moveset: " << endl;
            for (int i = 0; i < cerbiatto_instance.moves.size(); i++){
                cout << i +1 << ") " << global_moveset[cerbiatto_instance.moves[i]].name << endl;
            }
        }
        if (opt == 2){
            cerbiatto_instance2.levelup();
            cout << "Creature Status:" << endl
                 << "Name: " << cerbiatto_instance2.name << endl
                 << "Level: " << cerbiatto_instance2.lvl << endl
                 << "HP: " << cerbiatto_instance2.hp << "/" << cerbiatto_instance2.hpmax << endl
                 << "Mana: " << cerbiatto_instance2.mana << endl
                 << "XP: " << cerbiatto_instance2.xp << "/" << cerbiatto_instance2.xp_treshold << endl
                 << "Stats: " << endl
                 << "atk: " << cerbiatto_instance2.stats[0] << endl
                 << "def: " << cerbiatto_instance2.stats[1] << endl
                 << "matk: " << cerbiatto_instance2.stats[2] << endl
                 << "mdef: " << cerbiatto_instance2.stats[3] << endl
                 << "spd: " << cerbiatto_instance2.stats[4] << endl;

            cout << "Moveset: " << endl;
            for (int i = 0; i < cerbiatto_instance2.moves.size(); i++){
                cout << i +1 << ") " << global_moveset[cerbiatto_instance2.moves[i]].name << endl;
            }
        }

        if (opt == 3){
            for (int i = 0; i < global_moveset.size(); i++){
                cout << global_moveset[i].name << endl;
            }
        }

        if (opt == 4){
            cerbiatto_instance2.xp += 100;
        }

    } while (opt != 0);

    return 0;
}
