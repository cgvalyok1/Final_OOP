#include <iostream>
#include "enemy.h"

using namespace std;

void Goblin::Saysmth() const
{
    cout << "I AM A GOBLIN!! AAARGHH!!" << endl;
}

void Dragon::Saysmth() const 
{
    cout << "I AM A DRAGON!! RAAAWR!!" << endl;
}

void EnemyCreator::CREATION() const 
{
    Enemy* enemy = this->FactoryMethod();
    cout << "NEW CHALLENGER!!" << endl;
    enemy->Saysmth();
    delete enemy;
}

Enemy* GoblinCreator::FactoryMethod() const {
    return new Goblin();
}

Enemy* DragonCreator::FactoryMethod() const {
    return new Dragon();
}

