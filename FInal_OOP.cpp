#include <iostream>
#include "character.h"
#include "player.h"
#include "enemy.h"

using namespace std;

/*  
*   Strategy паттерн используется в классе Character
*   Memento (снимок) паттерн используется с классом player (в том же файле) для
*   запоминания прошлых ников.
*   Factory используется с классом enemyfactory для создания
*/

using namespace std;

int main()
{
    Player* player = new Player(new Warrior);
    cout << "Player class was set as Warrior" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Mage);
    cout << "Player class was set as Mage" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Dogge);
    cout << "Player class was set as Dogge" << endl;
    player->Attack();
    cout << endl;

    player->set_character(new Archer);
    cout << "Player class was set as Archer" << endl;
    player->Attack();
    player->Attack();
    player->Reload();
    player->Reload();
    player->Attack();

    cout << endl;
    
    Caretaker* caretaker = new Caretaker(player);
    cout << "Player: my nickname is " << player->get_nickname() << endl;
    caretaker->addMemento();
    player->set_nickname("CGValyok");
    cout << "Player: my nickname is " << player->get_nickname() << endl;
    caretaker->ShowHistory();
    caretaker->undo_to_Memento();
    cout << "Player: my nickname is " << player->get_nickname() << endl;

    cout << endl;  
    EnemyFactory* factory = new EnemyFactory();
    Enemy* enemy = factory->GoblinCreator(2);
    enemy->Saysmth();
    enemy = factory->GoblinCreator(1);
    enemy->Saysmth();
    enemy = factory->DragonCreator();
    enemy->Saysmth();
    

    delete enemy;
    delete factory;
    delete player;
    delete caretaker;
    return 0;
}
