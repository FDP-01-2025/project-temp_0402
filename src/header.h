#ifndef HEADER_H
#define HEADER_H
#include <iostream>
#include <string>
using namespace std;
struct Character {
    string name;
    int health;
    int attack;
    int defense;
    bool isDefending;
    int tempDefense;
};
extern Character player;
extern Character enemies[5];
void initializePlayer();
void initializeEnemies();
void showStatus(Character enemy);
Character playerTurn(Character enemy);
Character enemyTurn(Character enemy);
bool combat(Character enemy);
void levelUp();
void startGame();
#endif // HEADER_H