#include "RPG.h"

#include <iomanip>
#include <iostream>
#include <random>
//Default constructor
RPG::RPG() {
    name = "NPC";
    hits_taken = 0;
    luck = 0.1;
    exp = 50.0;
    level = 1;
}

//Overloaded/parameterized constructor
RPG::RPG(string name, int hits_taken, float luck, float exp, int level){
    this->name = name;
    this->hits_taken = hits_taken;
    this->luck = luck;
    this->exp = exp;
    this->level = level;
}

//Returns true when the player taken fewer than the max number hits
bool RPG::isAlive() const {
    if (hits_taken < MAX_HITS_TAKEN){
        return true;
    }
    return false;
}

//Sets number hits taken to supplied value
void RPG::setHitsTaken(int new_hits){
    hits_taken = new_hits;
}

//Accessor functions
string RPG::getName() const{
    return name;
}

int RPG::getHitsTaken() const {
    return hits_taken;
}

float RPG::getLuck() const {
    return luck;
}

float RPG::getExp() const {
    return exp;
}

int RPG::getLevel() const {
    return level;
}

//new function definitions 

/*updates name*/
void RPG::setName(string new_name){
    name = new_name;
}

/*increase by 50 if the exp >= 100 increase level by 1 then reset 0 increase luck by 0.1*/
void RPG::updateExpLevel(){
    exp += 50.0;
    if (exp >= 100.0){
        level++;
        exp = 0.0;
        luck += 0.1;
    }
}

/*hit or miss opp at random, luck is form of defense, higher opponents luck more likely it'll miss, if hit opp hit # ++*/
void RPG::attack(RPG* opponent){

    random_device rd; 
    mt19937 gen(rd()); //seed w/ random
    uniform_real_distribution<double> dis (0.0, 1.0); 

    float random_num = dis(gen); 

    //create bool called hit true -> random_num > HIT_FACTOR * opponent's luck 

    const float HIT_FACTOR = 1.0;

    bool hit = random_num > HIT_FACTOR * opponent->getLuck();

    //if hit true update hits taken
    
    if(hit){
        opponent->setHitsTaken(opponent->getHitsTaken() +1);
    }

}

/*prints in format 
"Name:NPC_X     Hits Taken: X   Luck: 0.X0000   Exp: X0.0000    Level: X    Status: Alive or Dead"*/

void RPG::printStats() const {
     cout << fixed << setprecision(6)
        <<"Name: " << name 
         <<"  Hits Taken: " << hits_taken 
         << "  Luck: " << luck 
         << "  Exp: " << exp 
         << "  Level: " << level 
         << "  Status: " << ((isAlive) ? "Alive" : "Dead") 
         << endl;
}

RPG::~RPG() {}