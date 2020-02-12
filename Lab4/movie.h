/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <string>
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


private:
    string openingCredits;

}; #pragma once
