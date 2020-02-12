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

        cout << "What Episode would you like?" << endl;
    TVshow.setEpisode(episode);
        cin >> episode;

        cout << showList[season][episode];

    }

    void details() {
        cout << "The title is: " << TVshow::getTitle() << endl;

        cout << "The description is: " << TVshow::getDesc() << endl;

        numSeasons = sizeof(showList) / sizeof(showList[0])

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
