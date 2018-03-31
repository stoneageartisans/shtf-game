/*
 * William Mann
 * November 15th, 2017
 * CSC275 Final Project
 * File:  Game.cpp
 */

#include "Game.h"
#include "Person.h"

#include <cstdlib>
#include <ctime>
#include <fstream>

#include <boost/math/special_functions/round.hpp>

using boost::math::iround;

Game::Game()
{
    initialize();
}

Game::~Game()
{
    // Clean up the pointers
    for(Person* person : data->people)
    {
        delete person;
    }
    
    delete data;
}

void Game::checkForEvent()
{
    // TODO
    
    /*
     * This will randomly check for an event occurrence. If an even occurs, the
     * event type will be randomly determined.
     */
}

void Game::endTurn()
{
    // TODO
    
    /*
     * This will process all the actions taken and apply the effects.
     * 
     * Food & Water will each be depleted at a rate of 1 per person.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::findNewShelter()
{
    // TODO
    
    /*
     * Attempt to find better shelter. If found you can abandon your current
     * shelter and move to the new one.
     * 
     * The max food you can bring is equal to your base action points.
     * 
     * The max water you can bring is equal to your base action points.
     * 
     * Action Point Cost:  2 per person (can abandon people at the cost of karma)
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

int Game::getRandom(int lowest, int highest)
{
    // Returns a random number from the range given (inclusive)
    return ( rand() % (highest - lowest + 1) ) + lowest;
}

int Game::getRandom(int arraySize)
{
    // Returns a random index number from the array size passed
    return ( rand() % arraySize );
}

void Game::improveShelter()
{
    // TODO
    
    /*
     * Action Point Cost is equal to the shelter's capacity value.
     * 
     * This will raise the shelter's condition by one level, which will improve
     * its protective rating.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::initialize()
{
    // Seed the random number generator with the current time
    srand( time(NULL) );
    
    loadNames();
    
    data = new GameData;
    
    data->location = getRandom(Location::COUNT);
    data->shelter = Shelter(data->location);
    
    int groupSize = getRandom(1, MaxStartingPeople);
    
    if( data->shelter.getCapacity() != Unlimited )
    {
        if( groupSize > data->shelter.getCapacity() )
        {
            groupSize = data->shelter.getCapacity();
        }
    }
    
    if(ShelterType::MaxInitialResources[data->shelter.getType()] == 0)
    {
        data->food = getRandom(0, groupSize);
    }
    else
    {
        data->food = getRandom( ShelterType::MaxInitialResources[data->shelter.getType()] / 2, ShelterType::MaxInitialResources[data->shelter.getType()]);
        data->food = iround( (float) data->food * ShelterCondition::RatingModifier[data->shelter.getCondition()] );
    }
    
    if(ShelterType::MaxInitialResources[data->shelter.getType()] == 0)
    {
        data->water = getRandom(0, groupSize);
    }
    else
    {
        data->water = getRandom( ShelterType::MaxInitialResources[data->shelter.getType()] / 2, ShelterType::MaxInitialResources[data->shelter.getType()]);
        data->water = iround( (float) data->water * ShelterCondition::RatingModifier[data->shelter.getCondition()] );
    }
    
    switch( data->shelter.getFeature() )
    {
        case ShelterFeature::WATER_SMALL:
            data->water += 10;
            break;
        case ShelterFeature::WATER_MEDIUM:
            data->water += 25;
            break;
        case ShelterFeature::WATER_LARGE:
            data->water += 50;
            break;
    }

    data->people.push_back( new Person(IsPlayer) );
    
    for(int i = 1; i < groupSize; i ++)
    {
        /* 
         * Gender is used here to ensure a realistic mix
         * of female and male names. It has no effect otherwise.
         */
        int gender = getRandom(1, 100);
        
        if(gender < 52)
        {
            data->people.push_back( new Person(femaleNames) );
        }
        else
        {
            data->people.push_back( new Person(maleNames) );
        }
    }
    
    data->baseActionPoints = 0;
    
    for(const Person* person : data->people)
    {
        data->baseActionPoints += ( BaseAction - person->getHealth() );
    }
    
    data->actionPoints = data->baseActionPoints;
    
    data->karma = 0;
    
    menuChoice = 0;
    running = true;
    state = ACTION_MENU;
}

void Game::loadNames()
{
    fstream file;

	file.open(FemaleNames.c_str(), ios::in);

	if( file.is_open() )
	{
		while( file.good() )
		{
			string name;

			getline(file, name);

			if(name.size() > 0)
			{
				femaleNames.push_back(name);
			}
		}

		file.close();
	}
    
    file.open(MaleNames.c_str(), ios::in);

	if( file.is_open() )
	{
		while( file.good() )
		{
			string name;

			getline(file, name);

			if(name.size() > 0)
			{
				maleNames.push_back(name);
			}
		}

		file.close();
	}
}

void Game::processChoice(int menu)
{
    switch(menu)
    {
        case ACTION:
            switch(menuChoice)
            {
                case ActionMenu::IMPROVE_SHELTER:
                    state = IMPROVE_SHELTER;
                    break;
                case ActionMenu::NEW_SHELTER:
                    state = NEW_SHELTER;
                    break;
                case ActionMenu::FORAGE_SCAVENGE:
                    state = FORAGE_SCAVENGE;
                    break;
                case ActionMenu::REST_HEAL:
                    state = REST_HEAL;
                    break;
                case ActionMenu::NEW_LOCATION:
                    state = NEW_LOCATION;
                    break;
                case ActionMenu::END_TURN:
                    state = END_TURN;
                    break;
                case ActionMenu::EXIT:
                    state = EXITING;
                    break;
            }
            break;
        case BANISH:
            // TODO
            break;
        case LOCATION:
            // TODO
            break;
    }
}

void Game::processEvent()
{
    // TODO
    
    /*
     * This will process the event and apply the effects.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::rest()
{
    // TODO
    
    /*
     * Each action point alloted to this activity increases the
     * rate at which health rejuvenates.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::run()
{
    userInterface.displayMessage(IntroMessage, ClearScreen);    
    userInterface.pauseScreen(PauseMessage);
    
    while(running)
    {
        update();
    }
}

void Game::searchForResources()
{
    // TODO
    
    /*
     * Each action point alloted to this activity increases
     * the chance of finding food and/or water.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::showActionMenu()
{
    do
    {
        userInterface.displayStats(GameStats::FieldName, *data);
        userInterface.displayMenu(ActionMenu::COUNT, ActionMenu::ItemNames);
        userInterface.displayPrompt(PromptMessage, Indent);
    }
    while( !validateChoice( userInterface.getUserInput(), ActionMenu::COUNT) );
}

void Game::showBanishMenu()
{
    // TODO
    
    /*
     * Select a person to banish from your group. This will cost you karma.
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::showLocationMenu()
{
    // TODO
    
    /*
     * Abandon your current shelter and move to a different location.
     * 
     * New shelter type & condition will be randomly determined.
     * 
     * The max food you can bring is equal to your base action points.
     * 
     * The max water you can bring is equal to your base action points.
     * 
     * Action Point Cost:  2 per person (can abandon people at the cost of karma)
     * 
     *                   AVAILABLE LOCATION CHANGES      
     *              URBAN | SUBURBAN | RURAL | WILDERNESS
     *              -------------------------------------
     *       URBAN |  --  |   YES    |  NO   |    NO     |
     *    SUBURBAN | YES  |    --    |  YES  |    NO     |
     *       RURAL |  NO  |   YES    |  --   |    YES    |
     * WILDERNESSS |  NO  |    NO    |  YES  |    --     |
     *              -------------------------------------
     */
    
    state = ACTION_MENU; // temporary to prevent menu from getting stuck
}

void Game::update()
{
    switch(state)
    {
        case ACTION_MENU:
            showActionMenu();
            processChoice(GameMenu::ACTION);
            break;
        case IMPROVE_SHELTER:
            improveShelter();
            break;
        case NEW_SHELTER:
            findNewShelter();
            break;
        case FORAGE_SCAVENGE:
            searchForResources();
            break;
        case REST_HEAL:
            rest();
            break;
        case NEW_LOCATION:
            showLocationMenu();
            break;
        case BANISH_PERSON:
            showBanishMenu();
            break;
        case END_TURN:
            endTurn();
            checkForEvent();
            break;
        case EVENT:
            processEvent();
            break;
        case EXITING:
            running = false;
            break;
    }
}

bool Game::validateChoice(const string& userInput, int choiceCount)
{
    bool result = false;
    
    menuChoice = atoi(&userInput[0]);
    
    if(menuChoice > 0 && menuChoice < choiceCount)
    {
        result = true;
    }
    
    return result;
}
