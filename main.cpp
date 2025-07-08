#include "./src/game.cpp"
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