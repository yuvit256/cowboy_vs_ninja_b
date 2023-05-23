#ifndef TEAM2_H
#define TEAM2_H

#include "Team.hpp"
#include <string>

namespace ariel
{
    class Team2 : public Team
    {
    public:
        Team2(Character *);
        Team2();
        ~Team2();
        int stillAlive();
        void print();
        void add(Character *);
    private:
        vector<Character *> _group;
        Character *_leader;
    };
};

#endif