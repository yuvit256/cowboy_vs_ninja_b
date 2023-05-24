#include <iostream>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"

using namespace std;

namespace ariel
{
    Character::Character(Point pos, int hp1, string name)
    {
        this->_pos = pos;
        this->_hp = hp1;
        this->_name = name;
    }

    Character::Character()
    {
        this->_pos = Point();
        this->_hp = 100;
        this->_name = "Yuval";
    }

    bool Character::isAlive()
    {
        if (this->_hp > 0)
        {
            return true;
        }
        return false;
    }

    double Character::distance(Character *other) const
    {
        double dis = this->_pos.distance(other->_pos);
        return dis;
    }

    void Character::hit(int dmg)
    {
        if (dmg < 0)
        {
            throw invalid_argument("damage cannot be negative");
        }
        if (this->_hp < dmg)
        {
            this->_hp = 0;
        }
        else
        {
            this->_hp -= dmg;
        }
    }

    string Character::getName() const
    {
        return this->_name;
    }

    Point Character::getLocation() const
    {
        return this->_pos;
    }

    int Character::getHp() const
    {
        return this->_hp;
    }

    void Character::setInTeam(bool inTeam)
    {
        this->_inTeam = inTeam;
    }

    bool Character::getInTeam() const
    {
        return this->_inTeam;
    }

    string Character::print()
    {
        if (this->isAlive())
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this))
            {
                string pos = "(" + to_string(this->_pos.getX()) + ", " + to_string(this->_pos.getY()) + ")";
                return "C Name: " + this->_name + "\nHitPoints: " + to_string(this->_hp) + "\nPosition: " + pos + "\n";
            }
            else
            {
                string pos = "(" + to_string(this->_pos.getX()) + ", " + to_string(this->_pos.getY()) + ")";
                return "N Name: " + this->_name + "\nHitPoints: " + to_string(this->_hp) + "\nPosition: " + pos + "\n";
            }
        }
        else
        {
            if (Cowboy *cowboy = dynamic_cast<Cowboy *>(this))
            {
                string pos = "(" + to_string(this->_pos.getX()) + ", " + to_string(this->_pos.getY()) + ")";
                return "C (Name: " + this->_name + ")" + "\nPosition: " + pos + "\n";
            }
            else
            {
                string pos = "(" + to_string(this->_pos.getX()) + ", " + to_string(this->_pos.getY()) + ")";
                return "N (Name: " + this->_name + ")" + "\nPosition: " + pos + "\n";
            }
        }
    }
}