#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    virtual ~Enemy() {}
    virtual void Saysmth() const = 0;
};

class Goblin : public Enemy {
private:
    int hp;
    int atck;
    int resistance;
    const char* name;
public:
    Goblin(int s);
    void Saysmth() const override;
};
class Dragon : public Enemy {
private:
    int hp = 1000;
    int atck = 500;
    int resistance = 250;
public:
    void Saysmth() const override;
};


class EnemyFactory {
public:
    EnemyFactory() {}
    Enemy* GoblinCreator(int s);
    Enemy* DragonCreator();

};

#endif