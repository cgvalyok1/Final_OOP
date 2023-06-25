#ifndef ENEMY_H
#define ENEMY_H

class Enemy {
public:
    virtual ~Enemy() {}
    virtual void Saysmth() const = 0;
};

class Goblin : public Enemy {
public:
    void Saysmth() const override;
};
class Dragon : public Enemy {
public:
    void Saysmth() const override;
};

class EnemyCreator {
public:
    virtual ~EnemyCreator() {};
    virtual Enemy* FactoryMethod() const = 0;

    void CREATION() const;
};

class GoblinCreator : public EnemyCreator {

public:
    Enemy* FactoryMethod() const override;
};

class DragonCreator : public EnemyCreator {
public:
    Enemy* FactoryMethod() const override;
};

#endif