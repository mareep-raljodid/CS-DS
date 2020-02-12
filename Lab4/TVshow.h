/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

class TVshow : Service {
public:

    TVshow(); //Default constructor

    TVshow(int ep, int sn) {   //overload constructor
        season = sn;
        episode = ep;
    }


    void setEpisode(int ep) {        //getters and setters
        episode = ep;
    }

    void setSeason(int sn) {
        season = sn;
    }

    int getSeason() {
        return season;
    }

    int getEpisode() {
        return episode;
    }



    virtual int Play() {
        cout << "What show would you like?" << endl;
        cin >> show;

        TVshow::setTitle(show);

        cout << "What season would you like?" << endl;
        cin >> season;
        TVshow.setSeason(season);

        cout << TVshow.getSeason();


        cout << "What Episode would you like?" << endl;
        TVshow.setEpisode(episode);
        cin >> episode;
        
        cout << TVshow.getEpisode();



        cout << showList[season][episode];

    }

    void details() {
        cout << "The title is: " << TVshow::getTitle() << endl;

        cout << "The description is: " << TVshow::getDesc() << endl;

        numSeasons = sizeof(showList) / sizeof(int)

        cout << "The number of seasons is: " << numSeasons << endl;
    }

private:
    int season;
    int numSeasons;
    int episode;
    string show;
    int showList[season][episode];



};
#pragma once
