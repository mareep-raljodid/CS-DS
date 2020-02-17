/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */
#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <string>
#include "service.h"
using namespace std;


class Movie : public Service {

public:
    Movie();
    void SetopeningCredits(string credits);

    string GetopeningCredits();

    virtual void Play();
private:
    string openingCredits;
    string cred;
}; 

#endif
