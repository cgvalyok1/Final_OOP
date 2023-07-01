#ifndef PLAYER_H
#define PLAYER_H
#include <string>
#include <vector>
#include "character.h"


class Memento;

class Player
{
private:
    Character* charctr;
    std::string nickname = "player";
public:
    Player(Character* ch);
    ~Player();
    void set_character(Character* ch);
    void Attack();
    void Reload();

    std::string get_nickname();
    void set_nickname(std::string nick);
    Memento* Save();

    void Restore(Memento* memento);
};

class Memento
{
private:
    std::string nickname;
public:
    Memento(std::string nick);
    std::string get_nickname();
};


class Caretaker {
private:
    std::vector<Memento*> mementos;
    Player *player;
public:

    Caretaker(Player* playr);
    void addMemento();
    void undo_to_Memento();
    void ShowHistory() const;
};

#endif