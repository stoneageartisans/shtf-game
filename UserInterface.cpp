/*
 * William Mann
 * November 15th, 2017
 * CSC275 Final Project
 * File:  UserInterface.cpp
 */

#include "UserInterface.h"
#include "Person.h"

#include <cstdlib>
#include <iomanip>
#include <iostream>

using namespace std;

void UserInterface::displayMenu(int itemCount, const vector<string>& itemNames) const
{
    for(int item = 0; item < itemCount; item ++)
    {
        if(item == 0) // The menu heading
        {
            cout << itemNames[item] << endl;
        }
        else // The menu items
        {
            cout << "  " << item << " - " << itemNames[item] << endl;
        }
    }
}

void UserInterface::displayMessage(const string& message, bool clearScreen) const
{
    if(clearScreen)
    {
        CLEAR_SCREEN;
    }
    
    cout << message << endl;
}

void UserInterface::displayMessage(const vector<string>& multiLineMessage, bool clearScreen) const
{
    if(clearScreen)
    {
        CLEAR_SCREEN;
    }
    
    for(string line : multiLineMessage)
    {
        cout << line << endl;
    }
}

void UserInterface::displayPrompt(const string& promptMessage, bool indent) const
{
    if(indent)
    {
        cout << "  ";
    }
    
    cout << promptMessage;
}

void UserInterface::displayStats(const vector<string>& fields, GameData& gameData) const
{
    CLEAR_SCREEN;
    
    // Location
    cout << fields[GameStats::LOCATION] << ": " << Location::Name[gameData.location] << endl << endl;
    
    // Shelter
    cout << fields[GameStats::SHELTER] << ": " << gameData.shelter.getDisplayName() << endl;
    
    if( gameData.shelter.getCapacity() == Unlimited)
    {
        cout << "    " << fields[GameStats::SHELTER_CAPACITY] << ": Unlimited" << endl;
    }
    else
    {
        cout << "    " << fields[GameStats::SHELTER_CAPACITY] << ": " << gameData.shelter.getCapacity() << endl;
    }
    
    cout << "    " << fields[GameStats::SHELTER_RATING] << ": " << gameData.shelter.getRating() << endl;
    cout << "    " << fields[GameStats::SHELTER_FEATURE] << ": ";
    cout << ShelterFeature::Name[gameData.shelter.getFeature()] << endl << endl;
    
    // Food & Water
    cout << fields[GameStats::FOOD] << ": " << gameData.food << "    ";
    cout << fields[GameStats::WATER] << ": " << gameData.water << endl << endl;
    
    // People
    uint maxNameLength = 0;
    
    for(Person* person : gameData.people)
    {
        if(person->getName().length() > maxNameLength)
        {
            maxNameLength = person->getName().length();
        }
    }
    
    cout << fields[GameStats::PEOPLE] << ": " << gameData.people.size() << endl;
    
    for(Person* person : gameData.people)
    {
        cout << "    " << fields[GameStats::PERSON_NAME] << ": ";
        cout << person->getName() << setw( maxNameLength - person->getName().length() ) << "" << "   ";
        cout << fields[GameStats::PERSON_HEALTH] << ": ";
        cout << PersonHealth::Name[person->getHealth()] << endl;
    }
    
    cout << endl;
    
    // Action Points
    cout << fields[GameStats::ACTION_POINTS] << ": " << gameData.actionPoints << endl << endl;
}

string UserInterface::getUserInput()
{
    string userInput;
    
    getline(cin, userInput);
    
    return userInput;
}

void UserInterface::pauseScreen() const
{
    cin.get();
}

void UserInterface::pauseScreen(const string& pauseMessage) const
{
    cout << pauseMessage;
    
    cin.get();
}

void UserInterface::refreshInputBuffer()
{
    cin.clear();
    cin.ignore(1000, '\n');
}
