/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include "service.h"
#include "tvshow.h"
#include "movie.h"
#include <iostream>
#include <string>
using namespace std;

void printSE(Service &ss){
    ss.details();
    ss.Play();
}

bool exitp(){
    char y;
    cout << "Wanna do it again? (y/n): ";
    cin >> y;
    if ((y=='n') || (y=='N'))
        exit(0);
    else 
        return true;
}

int main(){
loop:
    string choice;
    string qq,qqq;
    cout << "\nInput title: " ;
    getline(cin,qq);
    cout << " \nYou entered:" << qq;
    cout << "\nInput Description: ";
    getline(cin,qqq);
    cout << " \nYou entered:" << qqq;
    Service showww(qq,qqq);
    cout << "\nCalling the special function that executes the play and details in a service object." << endl;
    printSE(showww);
    cout << "Press 1 for an instance of Show." << endl;
    cout << "Press 2 for an instance of Movie." << endl;
    cout << "Press 3 for an instance of TV Show." << endl;
    cout << "Press 4 for an instance of a MOVIE declared as a Show" << endl;
    cout << "Press 5 for an instance of a TV Show declared as a Show" << endl;
    cout << "Your choice: ";
    getline(cin,choice);
    cout << endl;
    string t,d;
    cout << "Input title: ";
    getline(cin,t);
    
    cout << "\nInput Description: ";
    getline(cin,d);
    
    Service show(t,d);
    cout << endl;
    if(choice == "1"){
        cout << "Service show() caller" << endl;
        show.Play();
        show.details();
    }

    if(choice == "2"){
        cout << "Movie show() caller" << endl;
        Movie *s1 = new Movie();
        s1->Play();
    }
    
    if(choice == "3"){
        int s,e;
        cout << "TVshow show() caller" << endl;
        cout << "Input season and eposode number" << endl;
        cin >> s;
        cin >> e;
        TVshow show2;
        show2.Play(show);
    }

    if(choice == "4"){
        cout << "Movie as Service caller" << endl;
        Service *s3 = new Movie;
        s3->Play();
    }

    if(choice == "5"){
        cout << "TVshow as Service caller" << endl;
        Service *s4 = new TVshow;
        s4->Play();
    }
    if(exitp())
        goto loop;
}
