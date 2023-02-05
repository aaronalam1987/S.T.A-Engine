#include "gameState.h"
#include <filesystem>

void CreateNew::entry() {
    std::cout << "=========================\n"
              << "Create new game file\n"
              << "=========================\n\n"
              << "\tEnter new filename:";
    std::cin.clear();
    std::cin.sync();
    getline(std::cin, filename);
    if (filename.empty()) {
        std::cout << "\nPlease enter a filename.\n\n";
        currentState->entry();
    } else {
        filename = filename + ext;
        if (std::filesystem::exists(filename)) {
            std::cout
                << "\nFile already exists, please use another filename.\n\n";
            currentState->entry();
        }
    }
}

void CreateNew::update() {
    sql = "CREATE TABLE GAMEDATA("
          "ID         INTEGER     PRIMARY KEY AUTOINCREMENT, "
          "PAGE_TEXT  TEXT    NOT NULL, "
          "OP1    TEXT    NOT NULL, "
          "L1     TEXT    NOT NULL, "
          "OP2    TEXT    NOT NULL, "
          "L2     TEXT    NOT NULL, "
          "OP3    TEXT    NOT NULL, "
          "L3     TEXT    NOT NULL, "
          "OP4    TEXT    NOT NULL, "
          "L4    TEXT    NOT NULL );";

    // Create database, insert SQL for table.
    int createDB = sqlite3_open(filename.c_str(), &DB);
    createDB = sqlite3_exec(DB, sql.c_str(), NULL, 0, NULL);

    // No error, things went well.
    if (createDB == SQLITE_OK) {
        std::cout << "\nNew game database created!\n";
        std::cout << "\tInsert data now? (Y/N): ";
        std::cin >> option;

        if (option == 'Y' || option == 'y') {
            std::cout << "insert data ";
        } else {
            currentState = mainMenu;
        }
    }

    // Something went wrong, notify and display error message thrown by sqlite.
    else {
        std::cout << "Failed to create database!\n";
    }
}

void CreateNew::leave() { sqlite3_close(DB); }