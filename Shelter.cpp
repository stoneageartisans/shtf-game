/*
 * William Mann
 * December 10th, 2017
 * CSC275 Final Project
 * File:  Shelter.cpp
 */

#include "Shelter.h"
#include "Constants.h"
#include "Game.h"


#include <boost/math/special_functions/round.hpp>

using boost::math::iround;

Shelter::Shelter()
{
    initialize(Location::SUBURBAN);
}

Shelter::Shelter(int location)
{
    initialize(location);
}

int Shelter::getCapacity() const
{
    return capacity;
}

int Shelter::getCondition() const
{
    return condition;
}

string Shelter::getDisplayName() const
{
    return displayName;
}

int Shelter::getFeature() const
{
    return feature;
}

int Shelter::getRating() const
{
    return rating;
}

int Shelter::getType() const
{
    return type;
}

void Shelter::initialize(int location)
{
    // Type
    switch(location)
    {
        case Location::URBAN:
            type = Urban::Shelter[Game::getRandom( Urban::Shelter.size() )];
            break;
        case Location::SUBURBAN:
            type = Suburban::Shelter[Game::getRandom( Suburban::Shelter.size() )];
            break;
        case Location::RURAL:
            type = Rural::Shelter[Game::getRandom( Rural::Shelter.size() )];
            break;
        case Location::WILDERNESS:
            type = Wilderness::Shelter[Game::getRandom( Wilderness::Shelter.size() )];
            break;
    }
    
    // Condition
    if(type == ShelterType::NO_SHELTER || type == ShelterType::CAVE)
    {
        condition = ShelterCondition::UNDEFINED;
    }
    else
    {
        switch(location)
        {
            case Location::URBAN:
                condition = Game::getRandom(ShelterCondition::RANSACKED, ShelterCondition::GUTTED);
                break;
            case Location::SUBURBAN:
                condition = Game::getRandom(ShelterCondition::ABANDONED, ShelterCondition::RANSACKED);
                break;
            case Location::RURAL:
                condition = Game::getRandom(ShelterCondition::ABANDONED, ShelterCondition::RANSACKED);
                break;
            case Location::WILDERNESS:
                condition = ShelterCondition::ABANDONED;
                break;
        }
    }
    
    // Display Name
    if(condition != ShelterCondition::UNDEFINED)
    {
        displayName += ShelterCondition::Name[condition];
        displayName += " ";
    }
    
    displayName += ShelterType::Name[type];
    
    // Capacity
    capacity = ShelterType::Capacity[type];
    
    if(capacity == RandomValue)
    {
        capacity = Game::getRandom(0, 10);
        
        if(capacity == 10)
        {
            capacity += Game::getRandom(0, 10);
            
            if(capacity == 20)
            {
                capacity += Game::getRandom(0, 10);
            }
        }
    }
    
    if(capacity == 0)
    {
        capacity = MinCapacity;
    }
    
    // Rating
    rating = iround( (float) ShelterType::Rating[type] * ShelterCondition::RatingModifier[condition] );
    rating += Location::RatingModifier[location];
    
    // Feature
    switch(location)
    {
        case Location::URBAN:
            feature = Urban::Feature[Game::getRandom( Urban::Feature.size() )];
            break;
        case Location::SUBURBAN:
            feature = Suburban::Feature[Game::getRandom( Suburban::Feature.size() )];
            break;
        case Location::RURAL:
            feature = Rural::Feature[Game::getRandom( Rural::Feature.size() )];
            break;
        case Location::WILDERNESS:
            feature = Wilderness::Feature[Game::getRandom( Wilderness::Feature.size() )];
            break;
    }
}
