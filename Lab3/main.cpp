#include <iostream>
#include <iomanip>
#include <math.h>
#include <signal.h>

#include "number.h"

using namespace std;

void annoyingHandler(int sig_num) {
    signal(SIGINT, annoyingHandler);
    cout << "\n Cannot be terminated using Ctrl+C, because this assignment was annoying. \n" << endl;
    cout << "You HAVE to type : I want to exit this program (without spaces)" << endl;
    fflush(stdout);
}

int main() {
    int a, c, b, d;
    float aa, bb;
    bool feelz = true;
    Number n1, n2;
   
    while (feelz == true){

        signal(SIGINT, annoyingHandler);

        int pp, kk;
        cout << "Please enter the value you would like to enter, is that polar or cartessian? (Enter 0 for polar)" << endl;
        cin >> pp;
        if (pp != 0){
            cout << "Please enter the number for first Complex Point:" << endl;
            cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
            cout << "Please enter A :  " ;
            cin >> a;
            cout << "\nPlease enter B: " ;
            cin >> b;
            Number n01(a,b);
            n1 = n01;
        }
        
        else {
            cout << "Please enter the number for first Complex Point:" << endl;
            cout << "Format is (r, Θ) here, r is the distance from origin and Θ is angle it makes with respect to X cordinate," << endl;
            cout << "Please enter r :  " ;
            cin >> a;
            cout << "\nPlease enter Θ: " ;
            cin >> aa;
            Number n01(a, aa);
            n1 = n01;
        }

        cout << "Enter the second number." << endl;
        cout << "Please enter the value you would like to enter, is that polar or cartessian? (Enter 0 for polar)" << endl;
        cin >> pp;
        if (pp != 0){
            cout << "Please enter the number for second Complex Point:" << endl;
            cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
            cout << "Please enter A :  " ;
            cin >> c;
            cout << "\nPlease enter B: " ;
            cin >> d;
            Number n02(c, d);
            n2 = n02;
        }

        else {
            cout << "Please enter the number for first Complex Point:" << endl;
            cout << "Format is (r, Θ) here, r is the distance from origin and Θ is angle it makes with respect to X cordinate," << endl;
            cout << "Please enter r :  " ;
            cin >> c;
            cout << "\nPlease enter Θ: " ;
            cin >> bb;
            Number n02(c, bb);
            n2 = n02;
        }

reet:
        char option;
        cout << "Enter a to add and s to do substract operation," << endl;
        cout << "Enter m for multiplication, and d for division." << endl;
        cout << "Enter option (a,s,m,d): ";
        cin >> option;

        switch (option) {

            case 'a':
                n1 + n2;
                cout << "Add Result: " ;
                n1.display();
                break;

            case 's': 
                n1 - n2;
                cout << "Substract Result: " ;
                n1.display();
                break;

            case 'm':
                cout << "Enter number to multiply with: ";
                cin >> kk;
                n1 * kk;
                n2 * kk;
                cout << "Multiplication Result (first number): " ;
                n1.display();
                cout << "Multiplication Result (second number): " ;
                n2.display();
                break;

           case 'd':
                cout << "Enter number to divide with: ";
                cin >> kk;
                n1 / kk;
                n2 / kk;
                cout << "Division Result (first number): " ;
                n1.display();
                cout << "Division Result (second number): " ;
                n2.display();
                break;
           case 'e':
                if(n1 == n2)
                    cout << "Two numbers are equal.";
                else
                    cout << "two numbers are not equal";
                break;
           default: 
                cout << "Wrong choice, try again." << endl;
                goto reet;
                break;
        }
        
        cout << "Would you like to operate on complex numbers again? (enter enter exit to exit): ";
        string s;
        cin >> s;
        if ((s != "exit") || (s != "iwanttoexitthisprogram"))
            feelz = true;
    }


}





