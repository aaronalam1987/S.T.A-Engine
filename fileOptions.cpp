#include "gameState.h"

void FileOptions::entry() {
    std::cout << "=========================\n"
              << "Modifying game file: " << filename << "\n"
              << "=========================\n\n"
              << "\t1. View game data\n"
              << "\t2. Insert new data\n"
              << "\t3. Remove data\n"
              << "\t4. Return to Main Menu\n"
              << "\t5. Exit\n\n"
              << "\tPlease selection an option:";
    std::cin >> option;
}

void FileOptions::update() {}

void FileOptions::leave() {}