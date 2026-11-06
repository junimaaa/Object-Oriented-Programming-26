#include <iostream>
#include<stdio.h>
#include "Charmander.h"
/**
 * @brief construct a new Charmander:: chamr obj
 * 
 */
Charmander::Charmander() : Pokemon(){
    type.push_back("Fire");
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "Default Contructor (Charmander)\n";
}

/**
 * @brief construct new chamr:: charm obj
 * 
 * @param name
 * @param hp
 * @param att 
 * @param def
 * @param t
 */
Charmander::Charmander(string name, int hp, int att, int def, vector<string> t, vector<string> s)
Pokemon(name, hp, att, def t,){
     type = t;
     skills = s;
     cout << "Overloaded Constructor (Charmander)\n";
}

/**
 * @brief says what chamr says
 * 
 */
void Charmander::speak(){
    cout << "Charmander-char\n";
}

/**
 * @brief calls print stats from parent class and apends the skills used for chamrander
 * 
 */
void Charmander::printStats(){
    Pokemon::printStats();
    cout <<"Skills: ";
    for(int i = 0; i < skills.size(); i++){
        cout << skills[i] << "\t";
    }
    cout << endl;
}