/*
 * William Mann
 * December 10th, 2017
 * CSC275 Final Project
 * File:  Shelter.h
 */

#ifndef SHELTER_H
#define SHELTER_H

#include <string>

using namespace std;

class Shelter
{
    public:
        Shelter();
        Shelter(int location);
        ~Shelter() {}
        int getCapacity() const;
        int getCondition() const;
        string getDisplayName() const;
        int getFeature() const;
        int getRating() const;
        int getType() const;
        
    private:
        void initialize(int location);
        int type;
        int capacity;
        int condition;
        int feature;
        string displayName;
        int rating;
};

#endif /* SHELTER_H */
