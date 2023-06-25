#include <iostream>
#include "character.h"
#include "crossbow.h"
#include "player.h"
#include "enemy.h"

using namespace std;

/*  
*   Strategy паттерн используется в классе Player
*   State в классе crossbow для определения готовности
*   Factory используется с классом enemy для создания и удаления (в данной реализации)
*   В будущем можно будет не удалять, а наоборот возвращать его и работать в функции битвы,
*   например, или еще как угодно.
*/

void Encounter(const EnemyCreator& creator)
{ //можно в будущем переделать в битву, возвращая в CREATION врага, и работать с ним тут
    creator.CREATION();
    cout << "Oops! Mysterious meteor struck its head and it died)" << endl;
    cout << endl;
}

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
    EnemyCreator* goblincreator = new GoblinCreator();
    EnemyCreator* dragoncreator = new DragonCreator();

    Encounter(*goblincreator);

    Encounter(*dragoncreator);

    delete goblincreator;
    delete dragoncreator;
    delete player;
    return 0;
}
