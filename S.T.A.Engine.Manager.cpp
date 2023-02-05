#include "gameState.h"

gameState *gameState::mainMenu = new MainMenu();
gameState *gameState::createNew = new CreateNew();
gameState *gameState::openExisting = new OpenExisting();
gameState *gameState::fileOptions = new FileOptions();
gameState *gameState::currentState = gameState::mainMenu;

int main() {
    while (true) {
        gameState::currentState->entry();
        gameState::currentState->update();
        gameState::currentState->leave();
    }
    return 0;
}