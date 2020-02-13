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

    void printShow(int a, int b) {
        cout << showList[a][b] << endl;
    }

    virtual void Play(Service &s) {
       
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

    void details() {
        cout << "The title is: " << TVshow::getTitle() << endl;

        cout << "The description is: " << TVshow::getDesc() << endl;

        numSeasons = sizeof(showList) / sizeof(int);

        cout << "The number of seasons is: " << numSeasons << endl;
    }

private:
    int season;
    int numSeasons;
    int episode;
    string show;
    int showList[25][25];



};
#endif
