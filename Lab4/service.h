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

class Service{
public: 

    Service(); //default constructor
    
    Service(string t, string d){   //overload constructor
        title = t;
        desc  = ;
    }
    
    void setTitle(string t){        //getters and setters
        title = t;
    }
    
    void setDesc(string d){
        desc = d;
    }
    
    string getTitle(){
        return title;
    }
    
    string getDesc(){
        return desc;
    }
    
    void details(){             //non-virtual details function
        cout << "Title: " << title << endl;
        cout << "Description: " << desc << endl;
    }
    
    virtual Play(); //virtual Play function

private:
    string title;
    string desc;
    
}