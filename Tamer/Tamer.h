#include <vector>
#include <string>
#include <cmath>



struct Move{
    std::string name;
    int power;
    int accuracy;
    int type; //0 physical, 1 magical, 2 status
    int effect; //0 none, 1 burn, 2 poison, 3 paralyze, 4 sleep
};


std::vector<Move> global_moveset;


struct creature{
    std::string name;
    std::vector<int> base_stats; // [atk, def, matk, mdef, spd, hp, growth_rate]
    std::vector<int> moves_learning_level;
    std::vector<Move> moveset;
    creature* evolution;
    int evolution_level;
    
};

struct creature_instance{
    std::string name;
    int lvl;
    int xp;
    int xp_treshold;
    int hp;
    int hpmax;
    std::vector<int> stats;
    std::vector<int> genetics;
    std::vector<Move> moves;
    std::vector<std::string> status;
    //get stats with
    creature* instance_of;
};


//example
//"ciao" has {wax_off, wax_on} as moves
//{wax_off, wax_on, cut} as moveset
//{0, 0, 7} as mll
//at lvl 7 it gets cut


creature_instance CreateInstance(creature base, std::vector<int> genetics_vector, std::string name){
    creature_instance giveback{
        name,
        1,
        0,
        1,
        base.base_stats[5] * genetics_vector[5],
        base.base_stats[5] * genetics_vector[5],
        {base.base_stats[0] * genetics_vector[0], base.base_stats[1] * genetics_vector[1], base.base_stats[2] * genetics_vector[2], base.base_stats[3] * genetics_vector[3], base.base_stats[4] * genetics_vector[4]},
        genetics_vector,
        {},
        {},
        &base
    };
    return giveback;
}


//change the 1.3 during testing to adjust game experience



void UpdateXpTreshold(creature_instance &instance){
    instance.xp_treshold = 10 * std::pow(instance.lvl, 1.3 / instance.instance_of->base_stats[6]);
}


void LevelUp(creature_instance &instance){
    instance.lvl++;
    UpdateXpTreshold(instance);
    for (int i = 0; i < instance.stats.size(); i++){
        instance.stats[i] += instance.instance_of->base_stats[i] * 0.1  * instance.genetics[i];
    }
}


