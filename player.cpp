#include <iostream>
#include "player.h"
#include <string>

Player::Player(Character* ch) : charctr(ch)
{
}

Player::~Player()
{
    delete this->charctr;
}

std::string Player::get_nickname()
{
    return nickname;
}

void Player::set_nickname(std::string nick)
{
    nickname = nick;
}

void Player::set_character(Character* ch)
{
    delete this->charctr;
    this->charctr = ch;
}

void Player::Attack()
{
    this->charctr->Attack();
}

void Player::Reload()
{
    this->charctr->Reload();
}

Memento* Player::Save() {
    return new Memento(this->nickname);
}

void Player::Restore(Memento* memento) {
    this->nickname = memento->get_nickname();
    std::cout << "Player: My nickname has changed to: " << this->nickname << std::endl;
}



Memento::Memento(std::string nick)
{
    this->nickname = nick;
}

std::string Memento::get_nickname()
{
    return nickname;
}



Caretaker::Caretaker(Player* playr)
{
    player = playr;
}

void Caretaker::addMemento() 
{
    mementos.push_back(this->player->Save());
}

void Caretaker::undo_to_Memento() 
{
    Memento* memento = this->mementos.back();
    this->mementos.pop_back();
    std::cout << "Caretaker: Restoring nickname to: " << memento->get_nickname() << "\n";
    this->player->Restore(memento);
}

void Caretaker::ShowHistory() const {
    std::cout << "Caretaker: Here's the list of mementos:\n";
    for (Memento* memento : this->mementos) {
        std::cout << memento->get_nickname() << "\n";
    }
}

