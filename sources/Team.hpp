#ifndef TEAM_H
#define TEAM_H

#include <vector>
#include <string>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
using namespace std;

namespace ariel
{
    class Team
    {
    protected:
        vector<Cowboy *> cowboys;
        vector<Ninja *> ninjas;
        vector<Character*> group;
        Character *leader;
    public:
        Team(Character *leader);
        Team();
        ~Team();
        virtual void add(Character *member);
        virtual void attack(Team *);
        virtual int stillAlive() const;
        virtual void print();
        Character *findClosest(Character *leader, vector<Character*> &) const;
    };
};

#endif