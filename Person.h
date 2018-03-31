/*
 * William Mann
 * December 13th, 2017
 * CSC275 Final Project
 * File:  Person.h
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <vector>

using namespace std;

class Person
{
    public:
        Person();
        Person(bool isPlayer);
        Person(const vector<string>& names);
        ~Person() {}
        int getHealth() const;
        string getName() const;

    private:
        void initialize(const vector<string>& names, bool isPlayer = false);
        int health;
        string name;
};

#endif /* PERSON_H */
