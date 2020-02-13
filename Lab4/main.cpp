/*
 * authors:
 *
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include "service.h"
#include "TVshow.h"
#include "movie.h"
#include <iostream>
#include <string>
using namespace std;

int main(){
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
        Movie show1;
        show1.Play();
    }
    

    


    return 0;
}
