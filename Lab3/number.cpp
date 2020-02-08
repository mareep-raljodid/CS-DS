/*
 * authors:
 * Rajdeep Bandopadhyay
 * Sarah George
 * Yulia Martinez
 */

#include <iostream>
#include <iomanip>
#include <math.h>
#include <cmath>

#include "number.h"

using namespace std;

#define PI 3.14159265


Number::Number() {

    img = 0;
    rel = 0;
}

Number::Number(double r, double i) {

    img = i;
    rel = r;
}

Number::Number(double r, float theta) {

    img = r * (sin(theta * PI / 180));
    rel = r * (cos(theta * PI / 180));
}

double Number::showPolarR(double r, double i) {
    double a = (i * i) + (r * r);
    a = sqrt(a);
    return a;
}

void Number::display (){

    cout << "Real: " << rel << endl;
    cout << "Imaginary: " << img << endl;
    cout << "Complex Form is: (" << rel << " + " << img <<"i)" << endl;
    cout << "Polar Form is: ("<<showPolarR(rel,img)<<", "<<showPolarAngle(rel,img)<<")" << endl;
}

double Number::showPolarAngle(double r, double i) {
    double a = (i * i) + (r * r);
    a = sqrt(a);

    double angle = acos(r / a);
    return angle;
}

