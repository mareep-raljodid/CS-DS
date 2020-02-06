#include <iostream>
#include <iomanip>
#include <math.h>

#include "number.h"

using namespace std;

int main() {
    int a, c, b, d;
    float aa, bb;
    cout << "Please enter the number for first Complex Point:" << endl;
    cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
    cout << "You can also enter 0 in B for making the equation Polar and A as r" << endl;
    cout << "Please enter A or r :>>  " ;
    cin >> a;
    cout << "\nPlease enter B (or enter 0 to enter degrees and provide polar format): " ;
    cin >> b;
    Number n1(a, b);
    if (b == 0){
        cin>>aa;
        Number n1(a, aa);
    }

    cout << "Please enter the number for second Complex Point:" << endl;
    cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
    cout << "You can also enter 0 in B for making the equation Polar and A as r" << endl;
    cout << "Please enter A or r :>> " ;
    cin >> c;
    cout << "\nPlease enter B (or enter 0 to enter degrees and provide polar format) :>> " ;
    cin >> d;
    Number n2(c, d);
    if (d == 0){
         cin>>bb;
         Number n2(c, bb);
     }
 
    int l;
    cout << "Would you like to add or substract these two numbers? (press 1 for  add and sunstract)" << endl;
    cout << "You can also enter something else (other than 2 or 1) for skipping to scalar number multiply or divide :>> ";
    cin >> l;
    if (l == 1){
        n1 + n2;
        cout << "Result: " ;
        n1.display();
        n1 - n2;
        cout << "Result: " ;
        n1.display();
    }

    int y,v, num;
    cout << "Would you like to multiply or divide one these number with a scalar quantity? (press 1 for multiply and divide operations) :>> " ;
    cin >> y;
    if (y == 1){
        cout << "Which number would you like to operate on, press 1 for first one or something else for second :>> " ;
        cin >> v;
        if (v == 1){
            cout << "Enter Scalar number to multiply with :>> " ;
            cin >> num;
            n1 * num;
            cout << "Result: " ;
            n1.display();

            cout  << "Enter Scalar number to divide with :>> " ;
            cin >> num;
            n1 / num;
            cout << "Result: " ;
            n1.display();
        }
        else {
            cout << "Enter Scalar number to multiply with :>> " ;
            cin >> num;
            n2 * num;
            cout << "Result: " ;
            n1.display();
  
            cout  << "Enter Scalar number to divide with :>> " ;
            cin >> num;
            n2 / num;
            cout << "Result: " ;
            n1.display();
        }
    }

    int t;
    cout << "Would you like to check two complex numbers for equality? (enter 1 for yes) :>> " ;
    cin >> t;
    if (t == 1){
        cout << "Please enter the number for first Complex Point:" << endl;
        cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
        cout << "You can also enter 0 in B for making the equation Polar and A as r" << endl;
        cout << "Please enter A or r :>> " ;
        cin >> a;
        cout << "\nPlease enter B (or enter 0 to enter degrees and provide polar format) :>> " ;
        cin >> b;
        Number n3(a, b);
        if (b == 0){
            cin>>aa;
            Number n3(a, aa);
        }

        cout << "Please enter the number for second Complex Point " << endl;
        cout << "Format is (A + Bi) here, A is real point and B is imaginary point while i being SQRT(-1)," << endl;
        cout << "You can also enter 0 in B for making the equation Polar and A as r" << endl;
        cout << "Please enter A or r :>> " ;
        cin >> c;
        cout << "\nPlease enter B (or enter 0 to enter degrees and provide polar format) :>> " ;
        cin >> d;
        Number n4(c, d);
        if (d == 0){
             cin>>bb;
             Number n4(c, bb);
        }

        if (n3 == n4)
            cout << "Two numbers you entered are equal!" << endl;
        else
            cout << "They are different. " <<endl;
    }

}





