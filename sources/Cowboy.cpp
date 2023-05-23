#include "Cowboy.hpp"
using namespace std;

namespace ariel
{
    Cowboy::Cowboy(string name, Point pos)
    {
        this->_name = name;
        this->_pos = pos;
        this->_ammo = 6;
        this->_hp = 110;
    }

    bool Cowboy::hasboolets() const
    {
        if (this->_ammo > 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }

    void Cowboy::shoot(Character *enemy)
    {
        if (!this->isAlive())
        {
            throw runtime_error("the attacker is dead");
        }
        if (!enemy->isAlive())
        {
            throw runtime_error("the victim is dead");
        }
        if (this == enemy)
        {
            throw runtime_error("can't attack himself");
        }
        if ((this->hasboolets()) && (this != enemy))
        {
            enemy->hit(10);
            this->_ammo--;
        }
    }

    void Cowboy::reload()
    {
        if (!this->isAlive())
        {
            throw runtime_error("the attacker is dead");
        }
        this->_ammo = 6;
    }

    int Cowboy::getAmmo()
    {
        return this->_ammo;
    }
}