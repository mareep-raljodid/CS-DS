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
    Movie(){
       
        cout << "Please type in Opening credits: ";
        cin >> openingCredits;
        SetopeningCredits(openingCredits);
        //defualt constructor
    }

    void SetopeningCredits(string credits) {
        openingCredits = credits;
    }

    string GetopeningCredits() {
        return openingCredits;
    }

    virtual void Play() {
        cout << "The opening credits are: " << endl;
        
        cred = GetopeningCredits();

        cout << cred << endl;

    }
private:
    string openingCredits;
    string cred;
}; 

