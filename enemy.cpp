#include <iostream>
#include "enemy.h"

using namespace std;

void Goblin::Saysmth() const
{
    cout << "I AM A "<< name << " GOBLIN!!AAARGHH!!" << endl;
    cout << "My Stats are " << hp << " " << atck << " " << resistance << endl;
}

Goblin::Goblin(int s)
{
    switch (s)
    {
    case 1:
        name = "GREEN";
        hp = 10;
        atck = 5;
        resistance = 3;
        break;
    case 2:
        name = "RED";
        hp = 40;
        atck = 10;
        resistance = 10;
        break;
    default:
        name = "ORDINARY";
        hp = 5;
        atck = 2;
        resistance = 0;
    }
    
}

void Dragon::Saysmth() const 
{
    cout << "I AM A DRAGON!! RAAAWR!!" << endl;
    cout << "My Stats are " << hp << " " << atck << " " << resistance << endl;
}

Enemy* EnemyFactory::GoblinCreator(int s)
{
    return new Goblin(s);
}

Enemy* EnemyFactory::DragonCreator()
{
    return new Dragon();
}

