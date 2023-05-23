#include "Team2.hpp"
#include <limits>
using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader)
    {
        if (leader == nullptr)
        {
            throw runtime_error("the leader can't be null");
        }
        if (leader->getInTeam())
        {
            throw runtime_error("the leader already has a team");
        }
        this->leader = leader;
        leader->setInTeam(true);
        this->_group.push_back(leader);
    }

    Team2::~Team2()
    {
        for (auto member : this->_group)
        {
            delete member;
        }
    }

    void Team2::add(Character *member)
    {
        if (member == nullptr)
        {
            throw runtime_error("the player can't be null");
        }
        if (member->getInTeam())
        {
            throw runtime_error("the player is already in team");
        }
        if (this->_group.size() < 10)
        {
            this->_group.push_back(member);
        }
        else
        {
            throw runtime_error("Team is full");
        }
        member->setInTeam(true);
    }

    int Team2::stillAlive()
    {
        int live = 0;
        for (auto member : this->_group)
        {
            if (member->isAlive())
            {
                live++;
            }
        }
        return live;
    }

    void Team2::print()
    {
        string str = "";
        for (auto member : this->_group)
        {
            str += member->print();
        }
        cout << str << endl;
    }
}