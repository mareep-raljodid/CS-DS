/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#ifndef SERVICE
#define SERVICE

#include <iostream>
#include <string>
using namespace std;

class Service {
public:

    Service(){
       // cout << "Default constructor of service called" << endl;
       title = "default";
       desc =  "default";
        //default constructor
    }

    Service(string t, string d) {   //overload constructor
        title = t;
        desc = d;
    }

    virtual void setTitle(string t) {        //getters and setters
        title = t;
    }

    void setDesc(string d) {
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



 
