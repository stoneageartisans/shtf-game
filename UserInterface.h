/*
 * William Mann
 * November 15th, 2017
 * CSC275 Final Project
 * File:  UserInterface.h
 */

#ifndef USERINTERFACE_H
#define USERINTERFACE_H

#include "Constants.h"

#include <string>
#include <vector>

using namespace std;

class UserInterface
{
    public:
        UserInterface() {}
        ~UserInterface() {}
        void displayMenu(int itemCount, const vector<string>& itemNames) const;
        void displayMessage(const string& message, bool clearScreen = false) const;
        void displayMessage(const vector<string>& multiLineMessage, bool clearScreen = false) const;
        void displayPrompt(const string& promptMessage, bool indent = false) const;
        void displayStats(const vector<string>& fields, GameData& gameData) const;
        string getUserInput();
        void pauseScreen() const;
        void pauseScreen(const string& pauseMessage) const;
        
    private:
        void refreshInputBuffer();
};

#endif /* USERINTERFACE_H */
