/*
 * William Mann
 * November 15th, 2017
 * CSC275 Final Project
 * File:  Game.h
 */

#ifndef GAME_H
#define GAME_H

#include "Constants.h"
#include "Person.h"
#include "Shelter.h"
#include "UserInterface.h"

#include <string>
#include <vector>

class Game
{
    public:
        Game();
        ~Game();
        GameData* data;
        static int getRandom(int lowest, int highest);
        static int getRandom(int arraySize);
        void run();
        
    private:
        vector<string> femaleNames;
        vector<string> maleNames;
        int            menuChoice;
        bool           running;
        GameState      state;
        UserInterface  userInterface;
        void checkForEvent();
        void endTurn();
        void findNewShelter();
        void improveShelter();
        void initialize();
        void loadNames();
        void processChoice(int menu);
        void processEvent();
        void rest();
        void searchForResources();
        void showActionMenu();
        void showBanishMenu();
        void showLocationMenu();
        void update();
        bool validateChoice(const string& userInput, int choiceCount);
};

#endif /* GAME_H */
