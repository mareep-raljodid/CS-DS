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

    TVshow:setTitle(show);

        cout << "What season would you like?" << endl;
        cin >> season;
    TVshow:setSeason(season);

        cout << "What Episode would you like?" << endl;
    TVshow:setEpisode(episode);
        cin >> episode;

    }



private:
    int season;
    int episode;
    string show;



};
#pragma once
