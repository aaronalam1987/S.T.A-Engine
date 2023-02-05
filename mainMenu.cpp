#include "gameState.h"

void MainMenu::entry() {
    std::cout << "=========================\n"
              << "S.T.A Engine Manager\n"
              << "=========================\n\n"
              << "\t1. Create a new game file\n"
              << "\t2. Open existing game file\n"
              << "\t3. Exit\n\n"
              << "\tPlease selection an option:";
    std::cin >> option;
}

void MainMenu::update() {
    std::map<int, gameState *> OptionsMap = {{1, createNew}, {2, openExisting}};
    if (option > 0 && option < 3) {
        currentState = OptionsMap[option];
    }
}

void MainMenu::leave() {}