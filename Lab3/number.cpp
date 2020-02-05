//
//  number.cpp
//  Lab3
//
//  Created by Sarah George on 2/5/20.
//  Copyright © 2020 Sarah George. All rights reserved.
//

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

Number::Number(int i, int r) {

    img = i;
    rel = r;
}

Number::Number(int r, float theta) {

    img = r * (sin(theta * PI / 180));
    rel = r * (cos(theta * PI / 180));
}

int Number::showPolarR(int i, int r) {
    int a = (i * i) + (r * r);
    a = sqrt(a);

    return a;
}

double Number::showPolarAngle(int i, int r) {
    int a = (i * i) + (r * r);
    a = sqrt(a);

    int angle = acos(r / a);
    return angle;
}

void Number::display() {
    cout << "Real: " << rel << endl;
    cout << "Imaginary: " << img << endl;
}
