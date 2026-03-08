#include "Tamer.h"

struct team{
    std::vector<creature_instance> members;
};



void apply_move(Puppa values){

}




int battle(team team1, team team2){
    int outcome = 0;
    int currentturn = 0;
    unsigned int BattleTimer = 0;
    //1     2       3
    //
    //   4      5       6



    //set initial timers
    for (int i = 0; i<team1.members.size(); i++){
        team1.members[i].set_timer();
    }
    for (int i = 0; i<team2.members.size(); i++){
        team1.members[i].set_timer();
    }


    while(true){
        BattleTimer++;

    // update timers
        for (int i = 0; i<team1.members.size(); i++){
            team1.members[i].timer--;
        }
        for (int i = 0; i<team2.members.size(); i++){
            team1.members[i].timer--;
        }


        // take turns
        for (int i = 0; i<team1.members.size(); i++){
            if (team1.members[i].timer == 0){
                currentturn = i+1;
                apply_move(team1.members[i].taketurn());
            }
        }
    


    }



    //return 1 if team1 wins, 2 if team2 wins
    return outcome;
}
