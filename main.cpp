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

Character player;
Character enemies[5];

void initializePlayer() {
    player = {"Dark Knight", 120, 12, 8, false, 0};
}

void initializeEnemies() {
    enemies[0] = {"Goblin", 40, 5, 4, false, 0};
    enemies[1] = {"Orc", 60, 7, 5, false, 0};
    enemies[2] = {"Dragon", 100, 10, 8, false, 0};
    enemies[3] = {"Magical Beast", 90, 9, 7, false, 0};
    enemies[4] = {"Final Boss", 150, 15, 12, false, 0};
}

void showStatus(Character enemy) {
    cout << "\n=== BATTLE STATUS ===";
    cout << "\n" << player.name << ": HP " << player.health<< " | ATK " << player.attack<< " | DEF " << player.defense;
    if (player.isDefending) {
        cout << " (DEF +" << player.tempDefense << ")";
    }

    cout << "\n" << enemy.name << ": HP " << enemy.health<< " | ATK " << enemy.attack<< " | DEF " << enemy.defense;
    if (enemy.isDefending) {
        cout << " (DEF +" << enemy.tempDefense << ")";
    }
    cout << "\n====================\n";
}

Character playerTurn(Character enemy) {
    int action;
    cout << "\nChoose action:\n";
    cout << "1. Attack\n";
    cout << "2. Defend\n";
    cout << "Your choice: ";
    cin >> action;

    if (action == 1) {
        int damage = player.attack - enemy.defense;
        if (enemy.isDefending) {
            damage -= enemy.tempDefense;
            if (damage < 0) damage = 0;
            enemy.isDefending = false;
        }
        if (damage < 1) damage = 1;
        enemy.health -= damage;
        cout << "You attacked " << enemy.name << " for " << damage << " damage!\n";
        player.isDefending = false;
    } 
    else if (action == 2) {
        player.tempDefense = 8 + player.defense;
        player.isDefending = true;
        cout << "You prepare to defend!\n";
    }
    else {
        cout << "Invalid choice! Try again.\n";
        return playerTurn(enemy);
    }
    return enemy;
}

Character enemyTurn(Character enemy) {
    if (enemy.health <= 0) return enemy;

    static bool shouldDefend = false;
    shouldDefend = !shouldDefend;

    if (shouldDefend) {
        enemy.tempDefense = 5 + enemy.defense;
        enemy.isDefending = true;
        cout << enemy.name << " prepares to defend!\n";
    } else {
        int damage = enemy.attack - player.defense;
        if (player.isDefending) {
            damage -= player.tempDefense;
            if (damage < 0) damage = 0;
            player.isDefending = false;
            cout << "You blocked part of the attack! ";
        }
        if (damage < 1) damage = 1;
        player.health -= damage;
        cout << enemy.name << " attacks you for " << damage << " damage!\n";
    }
    return enemy;
}

bool combat(Character enemy) {
    cout << "\n\nYou encounter a " << enemy.name << "!\n";

    while (player.health > 0 && enemy.health > 0) {
        showStatus(enemy);
        enemy = playerTurn(enemy);
        if (enemy.health <= 0) break;
        enemy = enemyTurn(enemy);
        if (player.health <= 0) {
            cout << "You have been defeated by " << enemy.name << "!\n";
            return false;
        }
    }

    cout << "You defeated " << enemy.name << "!\n";
    return true;
}

void levelUp() {
    player.attack += 3;
    player.defense += 2;
    player.health += 15;
    cout << "Level Up!\n";
    cout << "ATK +3 (" << player.attack << ")\n";
    cout << "DEF +2 (" << player.defense << ")\n";
    cout << "HP +30 (" << player.health << ")\n";
}

void startGame() {
    initializePlayer();
    initializeEnemies();
    cout << "=== DARK KNIGHT ADVENTURE ===\n";

    for (int i = 0; i < 5; i++) {
        if (!combat(enemies[i])) {
            cout << "\nGAME OVER\n";
            return;
        }
        levelUp();
    }

    cout << "\nCONGRATULATIONS! You saved the kingdom!\n";
}

int main() {
    startGame();
    return 0;
}