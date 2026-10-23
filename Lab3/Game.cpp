#include "Game.h"

#include <iostream>
#include <random>


Game::Game() {}
/*creates up to n RPG pointers and updates names w/ ordering, populates live player 0 to n- 1 as all alive initially*/
void Game::generatePlayers(int n) {
    for (int i = 0; i < n; i++) {
        players.push_back(new RPG());
        players[i]->setName("NPC_" + to_string(i));
        live_players.insert(i);
    }
}

/*int: index for vectors, players randomly selects them from alive and live players */
int Game::selectPlayer() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dist(0, static_cast<int>(live_players.size()) - 1);
   
    //random index
    int random_index = dist(gen);
    set<int>::iterator it = live_players.begin();
    advance(it, random_index);
    return *it;
}

// reset hits to 0 removes loser from live_players updatesExp prints npc x won against npc y 
// winner, loser, loserIndex 
void Game::endRound(RPG* winner, RPG* loser, int loser_index) {
    winner->setHitsTaken(0);
    live_players.erase(loser_index);
    winner->updateExpLevel();

    cout << winner->getName() << " won against "
     << loser->getName() << endl;
}

//call select player twice assign index if they are same restart battle round w/ if argument
void Game::battleRound() {
    int player_index_1 = selectPlayer();
    int player_index_2 = selectPlayer();

    if (player_index_1 == player_index_2) {
        battleRound();
        return;
    }

//create two RPG* player1 and player2 while they are alive attack each other, identify which is alive outside loop

    RPG* player1 = players[player_index_1];
    RPG* player2 = players[player_index_2];

    while (player1->isAlive() && player2->isAlive()) {
        player1->attack(player2);
        player2->attack(player1);
    }

    if (player1->isAlive()) {
        endRound(player1, player2, player_index_2);
    } else {
        endRound(player2, player1, player_index_1);
    }
}

/*runs until players.size is 1*/
void Game::gameLoop() {
    while (live_players.size() > 1) {
        battleRound();
    }
}

/*calls printstats*/
void Game::printFinalResults() {
    for (RPG* player : players) {
        player->printStats();
    }
}

Game::~Game() {}