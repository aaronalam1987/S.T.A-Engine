#include "gameState.h"
#include <filesystem>
#include <vector>
std::vector<std::string> fileResult;
int i;
void OpenExisting::entry() {
    std::cout << "=========================\n"
              << "Available game files: \n"
              << "=========================\n\n";

    for (const auto &fileList : std::filesystem::directory_iterator("./")) {
        if (fileList.path().filename().extension() == ".db") {
            std::cout << fileList.path().filename().replace_extension("")
                      << std::endl;
            i++;
        }
    }

    if (i == 0) {
        std::cout << "No available game files!\n";
    } else {
        std::cout << "\nEnter game filename:\n\n"
                  << "\tFilename:";
    }
    std::cin.clear();
    std::cin.sync();
    getline(std::cin, filename);
    filename = filename + ext;
}

void OpenExisting::update() {
    if (std::filesystem::exists(filename)) {
        currentState = fileOptions;

    } else {
        std::cout << "\n\nNo such file exists!\n";
        gameState::currentState->entry();
    }
}

void OpenExisting::leave() {}