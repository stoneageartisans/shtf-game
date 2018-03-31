/*
 * William Mann
 * November 16th, 2017
 * CSC275 Final Project
 * File:  Constants.h
 */

#ifndef CONSTANTS_H
#define CONSTANTS_H

#ifdef _WIN32
    #define CLEAR_SCREEN system("CLS")
#else
    #define CLEAR_SCREEN system("clear")
#endif

#include "Person.h"
#include "Shelter.h"

#include <string>
#include <vector>

using namespace std;

typedef struct 
{
    int             location;
    Shelter         shelter = 0;
    int             food;
    int             water;
    vector<Person*> people;
    int             baseActionPoints;
    int             actionPoints;
    int             karma;
} GameData;

const static int  BaseAction        = 3;
const static bool ClearScreen       = true;
const static bool Indent            = true;
const static bool IsPlayer          = true;
const static int  MinCapacity       = 1;
const static int  MaxCapacity       = 100;
const static int  MaxStartingPeople = 5;
const static int  RandomValue       = -1;
const static int  Unlimited         = -99;

const string FemaleNames   = "names_female.txt";
const string MaleNames     = "names_male.txt";
const string NoName        = "Unknown";
const string PlayerName    = "You";
const string PromptMessage = "Enter Choice: ";
const string PauseMessage  = "Press [ENTER] to continue";

const vector<string> IntroMessage =
{
    "The SHTF Game",
    "-------------",
    "Whether it was from an astroid impact, a solar flare,",
    "or a meglomanical tyrant that finally pushed the button,",
    "it really doesn't matter because the proverbial $#!^",
    "has hit the fan.",
    "",
    "You're goal is to thrive, but first you must survive.",
    "",
    "To survive you need food, water, and shelter.",
    "",
    "There is safety in numbers.",
    "",
    "Try not to lose your humanity...",
    ""
};

enum GameState
{
    ACTION_MENU,
    IMPROVE_SHELTER,
    NEW_SHELTER,
    FORAGE_SCAVENGE,
    REST_HEAL,
    NEW_LOCATION,
    BANISH_PERSON,
    END_TURN,
    EVENT,
    EXITING
};

enum GameMenu
{
    ACTION,
    LOCATION,
    BANISH
};

namespace GameStats
{
    enum Field
    {
        HEADING,
        LOCATION,
        SHELTER,
        SHELTER_CAPACITY,
        SHELTER_RATING,
        SHELTER_FEATURE,
        FOOD,
        WATER,
        PEOPLE,
        PERSON_NAME,
        PERSON_HEALTH,
        ACTION_POINTS,
        COUNT
    };
    
    const vector<string> FieldName =
    {
        "STATS",
        "Location",
        "Shelter",
        "Capacity",
        "Rating",
        "Feature",
        "Food",
        "Water",
        "People",
        "Name",
        "Health",
        "Action Points"
    };
}

namespace ActionMenu
{
    enum Item
    {
        HEADING,
        IMPROVE_SHELTER,
        NEW_SHELTER,
        FORAGE_SCAVENGE,
        REST_HEAL,
        NEW_LOCATION,
        BANISH_PERSON,
        END_TURN,
        EXIT,
        COUNT
    };
    
    const vector<string> ItemNames =
    {
        "ACTION MENU",
        "Improve Shelter",
        "Find New Shelter",
        "Forage / Scavenge",
        "Rest / Heal",
        "Change Location",
        "Banish Person",
        "End Turn",
        "Exit Game"
    };
}

namespace BanishMenu
{
    // TODO
}

namespace LocationMenu
{
    // TODO
}

namespace Location
{
    enum Type
    {
        URBAN,
        SUBURBAN,
        RURAL,
        WILDERNESS,
        COUNT
    };
    
    const vector<string> Name =
    {
        "Urban",
        "Suburban",
        "Rural",
        "Wilderness"
    };
    
    /* 
     * The surrounding terrain gives a bonus
     * to the protective rating of the shelter
     */
    const vector<int> RatingModifier =
    {
        1, // Urban
        0, // Suburban
        1, // Rural
        2  // Wilderness
    };
}

namespace ShelterType
{
    enum Type
    {
        NO_SHELTER,
        APARTMENT,
        AUTOMOBILE,
        CABIN,
        CAVE,
        CHURCH,
        GAS_STATION,
        HOUSE,
        MOBILE_HOME,
        OFFICE_BUILDING,
        SCHOOL,
        RESTAURANT,
        STORAGE_UNIT,
        WAREHOUSE,
        COUNT
    };
    
    const vector<string> Name =
    {
        "No Shelter",
        "Apartment",
        "Automobile",
        "Cabin",
        "Cave",
        "Church",
        "Gas Station",
        "House",
        "Mobile Home",
        "Office Building",
        "School",    
        "Store",
        "Restaurant",
        "Storage Unit",
        "Warehouse"
    };
    
    const vector<int> Capacity =
    {
        Unlimited,   // No Shelter
        6,           // Apartment
        2,           // Automobile
        5,           // Cabin
        RandomValue, // Cave
        25,          // Church
        10,          // Gas Station
        8,           // House
        7,           // Mobile Home
        100,         // Office Building
        50,          // School
        40,          // Store
        15,          // Restaurant
        40,          // Storage Unit
        50           // Warehouse
    };
    
    const vector<int> Rating =
    {
        0, // No Shelter
        3, // Apartment
        2, // Automobile
        3, // Cabin
        5, // Cave
        5, // Church
        4, // Gas Station
        4, // House
        3, // Mobile Home
        5, // Office Building
        5, // School
        5, // Store
        5, // Restaurant
        5, // Storage Unit
        5  // Warehouse
    };

    const vector<int> MaxInitialResources =
    {
        0,  // No Shelter
        6,  // Apartment
        1,  // Automobile
        5,  // Cabin
        0,  // Cave
        12, // Church
        20, // Gas Station
        8,  // House
        7,  // Mobile Home
        25, // Office Building
        25, // School
        80, // Store
        30, // Restaurant
        10, // Storage Unit
        12  // Warehouse
    };
}
 
namespace ShelterCondition
{
    enum Type
    {
        UNDEFINED,
        ABANDONED,
        RANSACKED,
        GUTTED,
        REINFORCED,
        FORTIFIED,
        COUNT
    };
    
    const vector<string> Name =
    {
        "Undefined",
        "Abandoned",
        "Ransacked",
        "Gutted",
        "Reinforced",
        "Fortified"
    };
    
    /* 
     * The condition of the shelter can modify
     * its protective rating and the amount of
     * food & water initially found inside.
     */
    const vector<float> RatingModifier =
    {
         1,    // Undefined
         1,    // Abandoned
         0.75, // Ransacked
         0.5,  // Gutted
         1.25, // Reinforced
         1.5   // Fortified
    };
}

namespace ShelterFeature
{
    enum Type
    {
        NONE,
        WATER_SMALL,
        WATER_MEDIUM,
        WATER_LARGE,
        COUNT
    };
    
    const vector<string> Name =
    {
        "NONE",
        "Small water source nearby",
        "Medium water source nearby",
        "Large water source nearby"
    };
}

namespace Urban
{
    const vector<int> Shelter =
    {
        ShelterType::NO_SHELTER,
        ShelterType::APARTMENT,
        ShelterType::AUTOMOBILE,
        ShelterType::CHURCH,
        ShelterType::GAS_STATION,
        ShelterType::OFFICE_BUILDING,
        ShelterType::SCHOOL,
        ShelterType::RESTAURANT,
        ShelterType::STORAGE_UNIT,
        ShelterType::WAREHOUSE
    };
    
    const vector<int> Feature = 
    {
        ShelterFeature::NONE
    };
}

namespace Suburban
{
    const vector<int> Shelter =
    {
        ShelterType::NO_SHELTER,
        ShelterType::APARTMENT,
        ShelterType::AUTOMOBILE,
        ShelterType::CHURCH,
        ShelterType::GAS_STATION,
        ShelterType::HOUSE,
        ShelterType::MOBILE_HOME,
        ShelterType::OFFICE_BUILDING,
        ShelterType::SCHOOL,
        ShelterType::RESTAURANT,
        ShelterType::STORAGE_UNIT,
        ShelterType::WAREHOUSE
    };
    
    const vector<int> Feature = 
    {
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::WATER_SMALL
    };
}

namespace Rural
{
    const vector<int> Shelter =
    {
        ShelterType::NO_SHELTER,
        ShelterType::AUTOMOBILE,
        ShelterType::CABIN,
        ShelterType::CHURCH,
        ShelterType::GAS_STATION,
        ShelterType::HOUSE,
        ShelterType::MOBILE_HOME,
        ShelterType::SCHOOL,
        ShelterType::RESTAURANT,
        ShelterType::STORAGE_UNIT,
        ShelterType::WAREHOUSE
    };
    
    const vector<int> Feature = 
    {
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::WATER_SMALL,
        ShelterFeature::WATER_MEDIUM,
        ShelterFeature::WATER_LARGE
    };
}

namespace Wilderness
{
    const vector<int> Shelter =
    {
        ShelterType::NO_SHELTER,
        ShelterType::AUTOMOBILE,
        ShelterType::CABIN,
        ShelterType::CAVE
    };
    
    const vector<int> Feature = 
    {
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::NONE,
        ShelterFeature::WATER_SMALL,
        ShelterFeature::WATER_SMALL,
        ShelterFeature::WATER_SMALL,
        ShelterFeature::WATER_MEDIUM,
        ShelterFeature::WATER_MEDIUM,
        ShelterFeature::WATER_LARGE
    };
}

namespace PersonHealth
{
    enum Type
    {
        GOOD,
        FAIR,
        POOR,
        COUNT
    };
    
    const vector<string> Name
    {
        "Good",
        "Fair",
        "Poor"
    };
}

namespace Event
{
    enum Type
    {
        WEATHER,
        GEOLOGICAL,
        ENCOUNTER,
        BIOLOGICAL,
        BUG_OUT,
        COUNT
    };
    
    const vector<string> Name
    {
        "Weather",
        "Geological",
        "Encounter",
        "Biological",
        "Bug-Out"
    };
}

#endif /* CONSTANTS_H */
