/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include "service.h"
#include "tvshow.cpp"
#include "movie.cpp"
#include <iostream>
#include <string>
using namespace std;

int main(){
loop:
    int choice;
    cout << "Press 1 for an instance of Show." << endl;
    cout << "Press 2 for an instance of Movie." << endl;
    cout << "Press 3 for an instance of TV Show." << endl;
    cout << "Press 4 for an instance of a MOVIE declared as a Show" << endl;
    cout << "Press 5 for an instance of a TV Show declared as a Show" << endl;
    cout << "Your choice: ";
    cin >> choice;
    string t,d;
    cout << "\nInput title: " ;
    cin >> t;
    cout << "\nInput Description: ";
    cin >> d;
    Service show(t,d);
    
    if(choice == 1){
        cout << "Service show() caller" << endl;
        show.Play();
        show.details();
    }

    if(choice == 2){
        cout << "Movie show() caller" << endl;
        Movie *s1 = new Movie();
        s1->Play();
    }
    
    if(choice == 3){
        int s,e;
        cout << "TVshow show() caller" << endl;
        //cout << "Input season and eposode number" << endl;
        //cin >> s;
        //cin >> e;
        TVshow show2;
        show2.Play(show);
    }

    if(choice == 4){
        cout << "Movie as Service caller" << endl;
        Service *s3 = new Movie;
        s3->Play();
    }

    if(choice == 5){
        cout << "TVshow as Service caller" << endl;
        Service *s4 = new TVshow;
        s4->Play();
    }
    char y;
    cout << "Wanna do it again? (y/n): ";
    cin>>y;
    if ((y == 'y') || (y == 'Y'))
        goto loop;
    return 0;
}
