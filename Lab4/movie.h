/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <string>
#include "service.h"
using namespace std;


class Movie : Service {

public:
    Movie();//defualt constructor

    void SetopeningCredits(string credits) {
        openingCredits = credits;
    }

    string GetopeningCredits() {
        return openingCredits;
    }

    virtual int Play() {
        cout << "The opening credits are: " << endl;
        
        cred = GetopeningCredits();

        cout << cred << endl;

    }
private:
    string openingCredits;
    string cred;
}; 
#pragma once
