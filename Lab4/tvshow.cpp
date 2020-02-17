/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef TVSHOW_H
#define TVSHOW_H

#include <iostream>
#include <string>
#include "tvshow.h"

using namespace std;

TVshow::TVshow(int ep, int sn) {   //overload constructor
        season = sn;
        episode = ep;
}

void TVshow::setEpisode(int ep) {        //getters and setters
    episode = ep;
}

void TVshow::setSeason(int sn) {
    season = sn;
}

int TVshow::getSeason() {
    return season;
}

int TVshow::getEpisode() {
    return episode;
}

void TVshow::printShow(int a, int b) {
    cout << showList[a][b] << endl;
}

void TVshow::Play(Service &s) {
       
    cout << "What show would you like?" << endl;
    cin >> show;

    s.setTitle(show);

    cout << "What season would you like?" << endl;
    cin >> season;
    setSeason(season);

    cout << getSeason();


    cout << "What Episode would you like?" << endl;
    setEpisode(episode);
    cin >> episode;
    
    cout << getEpisode();
    printShow(season, episode);

}

void TVshow::details() {
    cout << "The title is: " << TVshow::getTitle() << endl;

    cout << "The description is: " << TVshow::getDesc() << endl;

    numSeasons = sizeof(showList) / sizeof(int);

    cout << "The number of seasons is: " << numSeasons << endl;
}
#endif
