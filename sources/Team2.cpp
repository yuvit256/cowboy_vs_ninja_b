#include "Team2.hpp"
#include <limits>
using namespace std;

namespace ariel
{
    Team2::Team2(Character *leader) : Team(leader)
    {
    }

    Team2::~Team2()
    {
        for (auto member : this->_group)
        {
            delete member;
        }
        this->group.clear();
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