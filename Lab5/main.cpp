#include <iostream>
#include "RPG.h"

using namespace std;

/**
 * @brief Prints both player's name and their health
 * 
 * @param player 1
 * @param player 2
*/
void displayStats(RPG player1, RPG player2) {
    cout << player1.getName() << " Health: " << player1.getHealth() << endl;
    cout << player2.getName() << " Health: " << player2.getHealth() << endl;
}

/**
 * @brief displays who wins based on who is alive 
 * 
 * @param player1
 * @param player2
*/
void displayEnd(RPG player1, RPG player2){
    if (player1.isAlive() == true ){
        cout << player1.getName() << " has defeated " << player2.getName() << endl;

        //ends the nonexistent story
        cout << "Thus " << player2.getName() << "'s journey ends on a pathetic note." << endl;
        cout << "Meanwhile, " << player1.getName() << "'s journey is that of a legend to be." << endl;
        cout << "Regardless, this story has reached it's end and delivered it's message. Farewell." << endl;

    } else {
        cout << player2.getName() << " has defeated " << player1.getName() << endl;
        //ends the nonexistent story
        cout << "Thus " << player1.getName() << "'s journey ends on a pathetic note." << endl;
        cout << "Meanwhile, " << player2.getName() << "'s journey is that of a legend to be." << endl;
        cout << "Regardless, this story has reached it's end and delivered it's message. Farewell." << endl;

    }
}

/**
 * uses a while loop to check whether both players are alive
 * 
 * 
 * @param player1
 * @param player2
 * 
*/
void gameLoop(RPG * player1, RPG * player2){
    while (player1->isAlive()&&player2->isAlive()) {
        displayStats((*player1), (*player2));
        cout << player1->getName() << "'s turn" << endl;
        (*player1).useSkill(player2);
        printf("------------------------------------\n");

        displayStats((*player1), (*player2));
        cout << player2->getName() << "'s turn" << endl;
        (*player2).useSkill(player1);
        printf("---------------10---------------------\n");
    }
    
}


int main()
{
    RPG p1 = RPG("Wiz", 70, 45, 15, "mage");
    RPG p2 = RPG();
    //RPG p2 = RPG("God", 99999, 99999, 1, "GOD");

    gameLoop(&p1, &p2);
    displayEnd(p1, p2);
    return 0;

}