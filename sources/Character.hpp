#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include "Point.hpp"
using namespace std;

namespace ariel
{
    class Character
    {
        protected:
            Point _pos;
            int _hp;
            string _name;
            bool _inTeam = false;
        public:
            Character(Point pos, int hp1, string name);
            Character();
            virtual bool isAlive();
            double distance(Character *other) const;    
            void hit(int dmg);
            string getName() const;
            Point getLocation() const;
            virtual string print();
            int getHp() const;
            void setInTeam(bool inTeam);
            bool getInTeam() const;
    };
};

#endif