#include <iostream>
#include <iomanip>
#include <math.h>

#include "number.h"

using namespace std;

#define PI 3.14159265

Number::Number () {

    img = 0;
    rel = 0;
}

Number::Number (int i, int r) {

    img = i;
    rel = r;
}

Number::Number (int r, float theta) {

    img = r * ( sin (theta * PI / 180));
    rel = r * ( cos (theta * PI / 180)); 
 }

void Number::display (){

    cout << "Real: " << rel << endl;
    cout << "Imaginary: " << img << endl;
}


