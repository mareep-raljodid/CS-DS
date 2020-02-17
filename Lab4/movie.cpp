/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <string>
#include "movie.h"

using namespace std;

string openingCredits;

Movie::Movie(){
       
    cout << "Please type in Opening credits: ";
    cin >> openingCredits;
    SetopeningCredits(openingCredits);
    //defualt constructor
}

void Movie::SetopeningCredits(string credits) {
        openingCredits = credits;
    }

string Movie::GetopeningCredits() {
    return openingCredits;
}

void Movie::Play() {
    cout << "The opening credits are: " << endl;
    cred = GetopeningCredits();

    cout << cred << endl;

}