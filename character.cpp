#include <iostream>
#include "character.h"

using namespace std;

void Warrior::Attack()
{
    cout << "The enemy lost 10 hp from a sword slash" << endl;
}

void Warrior::Reload()
{
}

void Mage::Attack()
{
    cout << "The enemy lost 15 hp from a fireball" << endl;
}

void Mage::Reload()
{
}

void Dogge::Attack()
{
    cout << "The enemy lost 9999999999 hp from the Dogge's bark" << endl;
}

void Dogge::Reload()
{
}

void Archer::Attack()
{
    if (ready_to_shoot)
    {
        cout << "The enemy lost 10 hp from an arrow" << endl;
        ready_to_shoot = false;
    }
    else { cout << "Crossbow is not armed" << endl; }
}

void Archer::Reload()
{
    if (ready_to_shoot == true) { cout << "Crossbow is already armed" << endl; }
    else
    {
        ready_to_shoot = true;
        cout << "Crossbow has been reloaded" << endl;
    }
}