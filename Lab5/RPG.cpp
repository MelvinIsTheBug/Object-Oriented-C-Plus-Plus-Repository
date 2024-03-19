#include "RPG.h"
#include <iostream>

/**
 * @brief Construct a new RPG:: RPG object
 * 
*/
RPG::RPG()
{
   name = "NPC";
   health = 100;
   strength = 33;
   defense = 10;
   type = "warrior";
   skills[0] = "slash";
   skills[1] = "parry";
}

/**
 * @brief construct a new RPG:: RPG object
 * 
 * @param name
 * @param health
 * @param strength
 * @param defense
 * @param type
 * 
*/

RPG::RPG(string name, int health, int strength, int defense, string type)
{
    this->name = name;
    this->health = health;
    this->strength = strength;
    this->defense = defense;
    this->type = type;
    setSkills();

}

/// @brief 
/// @return 
string RPG::getName() const
{
    return name;
}

/// @brief 
/// @return 
int RPG::getHealth() const
{
    return health;
}

/// @brief 
/// @return 
int RPG::getStrength() const
{
    return strength;
}

/// @brief 
/// @return 
int RPG::getDefense() const
{
    return defense;
}

/**
 * @brief attack decreases the opponent's health by (strength- opponents defense)
 * 
 * @param opponent
*/
void RPG::attack(RPG * opponent){
    int opp_health = (*opponent).getHealth();
    int opp_def = (*opponent).getDefense();

    if (strength - opp_def > 0) {
        int new_health = opp_health - (strength - opp_def);
        (*opponent).updateHealth(new_health);
    } else {
        int new_health = opp_health - 0;
        (*opponent).updateHealth(new_health); 
    }

}

/**
* @brief Prompts the user to choose a skill and calls printAction() and attack()
*
* @param opponent
*/
void RPG::useSkill(RPG * opponent){
    for(int i=0; i < SKILL_SIZE; i++){
        printf("Skill %i: %s\n", i, skills[i].c_str());
    }

    //int created 
    int chosen_skill_index;

    //prompts user to choose skill
    printf("Choose a skill to use: Enter 0 or 1\n");

    // takes user input for chosen_skill_index
    cin >> chosen_skill_index;

    //chosen skill assigned to a string 
    string chosen_skill = skills[chosen_skill_index];

    printAction( chosen_skill, *opponent);
    attack(opponent);
}

/**
 * @brief sets the skills based on the RPG's role
 * 
*/

void RPG::setSkills() {
    if (type == "mage"){
        skills[0] = "fire";
        skills[1] = "thunder";
    } else if (type == "thief"){
        skills[0] = "pilfer";
        skills[1] = "jab";
    } else if (type == "archer"){
        skills[0] = "parry";
        skills[1] = "crossbow_attack";
    } else if (type == "Final Boss"){
        skills[0] = "Instant Elimination";
        skills[1] = "Unfair, Unblockable Instant Kill";     
    } else if (type == "GOD"){
        skills[0] = "Judgement";
        skills[1] = "Straight to the Gates";
    }   else{
        skills[0] = "slash";
        skills[1] = "parry";
    }
}

/**
 * @brief printAction thing?
*/
void RPG::printAction(string skill, RPG opponent) {
    printf("%s used %s on %s\n", name.c_str(), skill.c_str(), opponent.getName().c_str());
}

/**
 * @brief updates health into new health
 * 
 * @param new_health
*/
void RPG::updateHealth(int new_health) {
    health = new_health;
}


/**
 * @brief returns whether health is greater than 0
 * 
 * @return true
 * @return False
*/
bool RPG::isAlive() const {
    return health > 0;
}

