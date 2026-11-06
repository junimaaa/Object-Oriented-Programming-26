#ifndef CHARMANDER_h
#define CHARMANDER_h

#include <vector>
#include <string>
#include "Pokemon.h"
using namespace std;

class Charmander : public Pokemon{
    public:
        //constructors
        Charmander();
        Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s);
        //mutator functions
        void speak() /*override*/;
        void printStats()/*override*/;
    private:
        vector<string> skills;
        /*name , hp, attack, defense*/
};

#endif  