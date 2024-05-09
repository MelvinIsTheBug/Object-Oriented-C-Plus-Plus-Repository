#include <iostream>
#include "Charmander.h"
using namespace std;
//#include <windows.h>

int main() {
    // Charmander first = charmander();
    vector<string> pokemonType;
    pokemonType.push_back("Fire");

    vector<string> skills;
    skills.push_back("Growl");
    skills.push_back("Scratch");

    cout << "------Constructor Created------\n";
    Charmander charlie = Charmander("Charlie", 100, 4, 4, pokemonType, skills);
   
    //Charmander
    cout << "\n ------Direct Speak------\n";
    charlie.speak();

    //Pokemon pointer to Charmander
    Pokemon * p1 = &charlie;
    cout << "\n-----Speak called from Pokemon pointer-----\n";
    (*p1).speak();

    //Charmander pointer to Charmander 
    Pokemon * c1 = &charlie;
    cout << "\n-----Speak called from Pokemon pointer-----\n";
    (*c1).speak();

    //Charmander
    cout << "\n -------Print Stats-------\n";
    charlie.printStats();
}