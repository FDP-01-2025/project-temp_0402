#include <iostream>
using namespace std;

struct Character {
    string name;
    int health;
    int attack;
    int defense;
    bool isDefending;
    int tempDefense;
};

// Variables globales
Character player;
Character enemies[5];

void initializePlayer();
void initializeEnemies();
void showStatus(const Character &enemy);
void playerTurn(Character &enemy);
void enemyTurn(Character &enemy);
bool combat(Character &enemy);
void levelUp();
void startGame();

