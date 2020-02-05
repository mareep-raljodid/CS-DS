#include <iostream>
#include <iomanip>
#include <math.h>

#include "number.h"
using namespace std;

int main() {
    Number n1(13, 7);
    Number n2(11, 88.999);

    cout << n1 + n2;
}
