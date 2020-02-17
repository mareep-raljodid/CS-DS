#ifndef TVSHOW
#define TVSHOW
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

class TVshow : public Service {
public:

    TVshow(){} //Default constructor

    TVshow(int ep, int sn);


    void setEpisode(int ep);

    void setSeason(int sn);

    int getSeason();

    int getEpisode();

    void printShow(int a, int b);

    virtual void Play(Service &s);

    void details();

private:
    int season;
    int numSeasons;
    int episode;
    string show;
    int showList[25][25];

};
#endif
