#ifndef CHARACTER_H
#define CHARACTER_H

struct Character
{
    virtual void Attack() = 0;
    virtual void Reload() = 0;
};

class Warrior : public Character
{
public:
    void Attack();
    void Reload();
};

class Mage : public Character
{
public:
    void Attack();
    void Reload();
};

class Dogge : public Character
{
public:
    void Attack();
    void Reload();
};

class Archer : public Character
{
    bool ready_to_shoot = true;
public:
    void Attack();
    void Reload();
};

#endif