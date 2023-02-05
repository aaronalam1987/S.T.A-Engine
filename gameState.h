#ifndef GAMESTATE_H
#define GAMESTATE_H
#include <cstring>
#include <iostream>
#include <map>
#include <sqlite3.h>
#include <string>

class gameState {
  public:
    gameState() = default;
    virtual ~gameState() = default;
    virtual void entry() = 0;
    virtual void update() = 0;
    virtual void leave() = 0;
    static gameState *currentState;
    static gameState *mainMenu, *openExisting, *createNew, *fileOptions,
        *viewData, *insertData, *removeData;
    const std::string ext = ".db";
    std::string filename;
    std::string sql;
    sqlite3 *DB;
};

class MainMenu : public gameState {
  public:
    void entry();
    void update();
    void leave();

  private:
    int option;
};

class OpenExisting : public gameState {
  public:
    void entry();
    void update();
    void leave();

  private:
    int option;
};

class CreateNew : public gameState {
  public:
    void entry();
    void update();
    void leave();

  private:
    char option;
};

class FileOptions : public gameState {
  public:
    void entry();
    void update();
    void leave();

  private:
    int option;
};

#endif