#ifndef GAME_H
#define GAME_H

#include"RPG.h"

#include <set>
#include <vector> 

class Game {
    public:
        Game();
        void generatePlayers(int n);
        int selectPlayer();
        void endRound(RPG* winner, RPG* loser, int loser_index);
        void battleRound();
        void gameLoop();
        void printFinalResults();
        ~Game();
    private:
        vector<RPG*> players;
        set<int> live_players;
};

#endif