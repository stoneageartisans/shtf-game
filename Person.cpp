/*
 * William Mann
 * December 13th, 2017
 * CSC275 Final Project
 * File:  Person.cpp
 */

#include "Person.h"
#include "Constants.h"
#include "Game.h"

Person::Person()
{
    initialize( vector<string>() );
}

Person::Person(bool isPlayer)
{
    initialize( vector<string>(), isPlayer );
}

Person::Person(const vector<string>& names)
{
    initialize(names);
}

int Person::getHealth() const
{
    return health;
}

string Person::getName() const
{
    return name;
}

void Person::initialize(const vector<string>& names, bool isPlayer)
{
    if(isPlayer)
    {
        name = PlayerName;
    }
    else
    {
        if( names.empty() )
        {
            name = NoName;
        }
        else
        {
            name = names[Game::getRandom( names.size() )];
        }
    }
    
    health = Game::getRandom(PersonHealth::COUNT);
}
