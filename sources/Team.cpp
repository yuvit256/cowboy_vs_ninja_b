#include "Team.hpp"
#include <typeinfo>
#include <limits>
using namespace std;

namespace ariel
{
    Team::Team(Character *leader) : leader(leader)
    {
        if (leader == nullptr)
        {
            throw runtime_error("the leader can't be null");
        }
        if (leader->getInTeam())
        {
            throw runtime_error("the leader already has a team");
        }
        if (auto cowboy = dynamic_cast<Cowboy *>(leader))
        {
            cowboys.push_back(cowboy);
        }
        else if (auto ninja = dynamic_cast<Ninja *>(leader))
        {
            ninjas.push_back(ninja);
        }
        this->group.push_back(leader);
        leader->setInTeam(true);
    }

    Team::Team()
    {
    }

    int Team::stillAlive() const
    {
        int live = 0;
        for (Character *member : this->group)
        {
            if (member->isAlive())
            {
                live++;
            }
        }
        return live;
    }

    Team::~Team()
    {
        for (auto member : this->cowboys)
        {
            delete member;
        }
        for (auto member : this->ninjas)
        {
            delete member;
        }
    }

    void Team::add(Character *member)
    {
        if (member == nullptr)
        {
            throw runtime_error("the player can't be null");
        }
        if (member->getInTeam())
        {
            throw runtime_error("the player is already in team");
        }
        if ((this->group.size()) < 10)
        {
            if (auto cowboy = dynamic_cast<Cowboy *>(member))
            {
                cowboys.push_back(cowboy);
            }
            else if (auto ninja = dynamic_cast<Ninja *>(member))
            {
                ninjas.push_back(ninja);
            }
            member->setInTeam(true);
            this->group.push_back(member);
        }
        else
        {
            throw runtime_error("You reached the maximum number of players which is 10");
        }
    }

    Character *Team::findClosest(Character *leader, vector<Character *> &players) const
    {
        double closest = numeric_limits<double>::max();
        Character *closest_member = nullptr;
        Point pnt = leader->getLocation();
        for (Character *member : players)
        {
            if (member->isAlive())
            {
                if (closest > member->getLocation().distance(pnt))
                {
                    closest_member = member;
                    closest = member->getLocation().distance(pnt);
                }
            }
        }
        if (closest_member == nullptr)
        {
            throw runtime_error("Team is dead");
        }
        return closest_member;
    }

    void Team::attack(Team *enemy)
    {
        if (enemy == nullptr)
        {
            throw std::invalid_argument("enemy can't be null");
        }
        if (!this->leader->isAlive())
        {
            this->leader = findClosest(this->leader, this->group);
        }
        Character *victim = findClosest(this->leader, enemy->group);
        for (Cowboy *cowboy : this->cowboys)
        {
            if (cowboy->isAlive())
            {
                if (enemy->stillAlive() == 0)
                {
                    return;
                }
                if (!victim->isAlive())
                {
                    victim = findClosest(this->leader, enemy->group);
                }
                if (!cowboy->hasboolets())
                {
                    cowboy->reload();
                }
                else
                {
                    cowboy->shoot(victim);
                }
            }
        }
        for (Ninja *ninja : this->ninjas)
        {
            if (ninja->isAlive())
            {
                if (enemy->stillAlive() == 0)
                {
                    return;
                }
                if (!victim->isAlive())
                {
                    victim = findClosest(this->leader, enemy->group);
                }
                if (!(ninja->distance(victim) <= 1))
                {
                    ninja->move(victim);
                }
                else
                {
                    ninja->slash(victim);
                }
            }
        }
    }

    void Team::print()
    {
        string str = "";
        for (auto member : this->cowboys)
        {
            str += member->print();
        }
        for (auto member : this->ninjas)
        {
            str += member->print();
        }
        cout << str << endl;
    }
}