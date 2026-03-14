#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "../randomcust.h"

#define maxspd 750
#define maxstats 300

using namespace std;


//mosse
struct Move{
    string name;
    int power;
    int accuracy;
    bool types[4];  //0 physical, 1 magical, 2 status, 3 healing
    vector<string> effects;
    //1     2       3
    //
    //   4      5       6
};

//prototipi per la forward declaration
struct creature_instance;
struct team
{
    std::vector<creature_instance> members;
};

//serve per taketurn
struct Puppa{
    Move mossa;
    creature_instance &target;
    creature_instance &applier;
};

Move mossa1{
    "ciao",
    50,
    100,
    0,
    {},
};

vector<Move> global_moveset = {mossa1};


struct creature{
    string name;
    vector<int> base_stats; // [atk, def, matk, mdef, spd, hp]
    float growth_rate;
    vector<int> moves_learning_level;
    vector<int> moveset;  //moveset index
    creature* evolution;
    int evolution_level;
    
};

struct creature_instance{
    string name;
    int lvl;
    int xp;
    int xp_treshold;
    int hp;
    int hpmax;
    int mana; // x/5
    vector<int> stats;
    vector<float> genetics;
    vector<int> moves; //index of moveset
    vector<string> status;
    //get stats with
    creature* instance_of;
    int timer = 0;
    //int battle_position; may be useful

    void set_timer(){
        timer = maxspd - stats[4];
    }


    Puppa taketurn(team targets){

        cout << "Choose a move: " << endl;
        for (int i = 0; i < moves.size(); i++){
            cout << i+1 << ") " << global_moveset[moves[i]].name << endl;
        }
        int move_choice;
        cin >> move_choice;
        move_choice--;

        cout << "Choose a target: " << endl;
        for (int i = 0; i < targets.members.size(); i++){
            cout << i+1 << ") " << targets.members[i].name << " HP: " << targets.members[i].hp << "/" << targets.members[i].hpmax << endl;
        }
        int target_choice;
        cin >> target_choice;
        target_choice--;

        Puppa choice{
            global_moveset[moves[move_choice]],
            targets.members[target_choice],
            *this
        };
        return choice;
    }


    Puppa AItaketurn(team targets, int seed){

        Puppa choice{
            mossa1,
            targets.members[randomnum(seed)*1000 / targets.members.size()],
            *this
        };
        return choice;
    }

};


//example
//"ciao" has {wax_off, wax_on} as moves
//{wax_off, wax_on, cut} as moveset
//{0, 0, 7} as mll
//at lvl 7 it gets cut




// don't touch this
creature_instance CreateInstance(creature* base, vector<float> genetics_vector, string name){
    creature_instance giveback{
        name,
        1,
        0,
        1,
        (int)(base->base_stats[5] * genetics_vector[5]),
        (int)(base->base_stats[5] * genetics_vector[5]),
        5,
        {(int)(base->base_stats[0] * genetics_vector[0]), (int)(base->base_stats[1] * genetics_vector[1]), (int)(base->base_stats[2] * genetics_vector[2]), (int)(base->base_stats[3] * genetics_vector[3]), (int)(base->base_stats[4] * genetics_vector[4])},
        genetics_vector,
        {},
        {},
        base,
        0
    };
    return giveback;
}


//change the 1.3 during testing to adjust game experience



void UpdateXpTreshold(creature_instance &instance){
    //have no idea
    instance.xp_treshold = 10 * pow(instance.lvl-1, 1.3 / instance.instance_of->growth_rate) + 100;
}





void LevelUp(creature_instance &instance){
    instance.lvl++;
    UpdateXpTreshold(instance);
    for (int i = 0; i < instance.stats.size(); i++){
        instance.stats[i] += instance.instance_of->base_stats[i] * 0.1  * instance.genetics[i];
        if (instance.stats[i] > maxstats){
            instance.stats[i] = maxstats;
        }
    }
    instance.hpmax += (int)(instance.instance_of->base_stats[5] * 0.1  * instance.genetics[5]);
    instance.hp = instance.hpmax;
    instance.mana = 5;
    for (int i = 0; i < instance.instance_of->moves_learning_level.size(); i++){
        if (instance.lvl == instance.instance_of->moves_learning_level[i]){
            instance.moves.push_back(instance.instance_of->moveset[i]);
        }
    }
}




creature_instance Evolve(creature_instance &instance){
    creature_instance evoluzione;
    evoluzione = CreateInstance(instance.instance_of->evolution, instance.genetics, instance.instance_of->evolution->name);
    delete(&instance);
    return evoluzione;
}



creature mr_cerbiatto{"mr_cerbiatto", {100, 100, 100, 100, 100, 100}, 1.7, {1, 5, 7, 13}, {0}, nullptr, -1};
creature fleshgorger{"fleshgorger", {150, 80, 60, 95, 110, 80}, 1.5, {1, 5, 7, 13}, {0}, nullptr, -1};

creature_instance cerbiatto_instance = CreateInstance(&mr_cerbiatto, {1, 1, 1, 1, 1, 1}, "mr_istanza");
creature_instance cerbiatto_instance2 = CreateInstance(&mr_cerbiatto, {1.1, 0.9, 1, 1, 1.1}, "mr_istanza2");
creature_instance cerbiatto_instance3 = CreateInstance(&mr_cerbiatto, {0.8, 1.3, 1, 1.3, 0.7, 1}, "mr_istanza3");

