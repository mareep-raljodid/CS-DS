/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef SERVICEITEM
#define SERVICEITEM

#include <iostream>
#include <string>
using namespace std;


template <class T> {
public:


    T() {
        // cout << "Default constructor of service called" << endl;
        title = "default";
        desc = "default";
        //default constructor
    }

    T(string t, string d) {   //overload constructor
        title = t;
        desc = d;
    }

    virtual void setTitle(string t) {        //getters and setters
        title = t;
    }

    virtual void setDesc(string d) {
        desc = d;
    }

    string getTitle() {
        return title;
    }

    string getDesc() {
        return desc;
    }

    void details() {             //non-virtual details function
        cout << "Title: " << title << endl;
        cout << "Description: " << desc << endl;
    }

    virtual void Play() {} //virtual Play function

private:
    string title;
    string desc;

};

#endif
#pragma once
